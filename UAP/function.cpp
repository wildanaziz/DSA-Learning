#include "function.h"
#include <iostream>
#include <fstream>
#include <filesystem>

Node::Node(const std::string& path) {
    this->path = path;
    next = nullptr;
}

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(const std::string& path) {
    Node* newNode = new Node(path);
    if (rear) {
        rear->next = newNode;
    } else {
        front = newNode;
    }
    rear = newNode;
}

std::string Queue::dequeue() {
    if (front) {
        std::string path = front->path;
        Node* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
        return path;
    }
    return "";
}

bool Queue::empty() const {
    return front == nullptr;
}

bool fileExists(const std::string& filename) {
    return std::filesystem::exists(filename);
}

bool directoryExists(const std::string& dirname) {
    return std::filesystem::exists(dirname) && std::filesystem::is_directory(dirname);
}

void createFile(const std::string& filename, const std::string& directory = ".") {
    std::string fullPath = std::filesystem::path(directory) / filename;
    if (fileExists(fullPath)) {
        std::cout << "File already exists: " << fullPath << ". Do you want to overwrite it? (y/n): ";
        char response;
        std::cin >> response;
        if (response != 'y' && response != 'Y') {
            std::cout << "File creation aborted." << std::endl;
            return;
        }
    } else {    
        std::ofstream file(fullPath);
        if (file) {
            std::cout << "File created: " << fullPath << std::endl;
        } else {
            std::cerr << "Error creating file: " << fullPath << std::endl;
        }
    }
}

void createDirectory(const std::string& dirname, const std::string& directory = ".") {
    std::string fullPath = std::filesystem::path(directory) / dirname;
    if (directoryExists(fullPath)) {
        std::cout << "Directory already exists: " << fullPath << ". Do you want to recreate it? (y/n): ";
        char response;
        std::cin >> response;
        if (response != 'y' && response != 'Y') {
            std::cout << "Directory creation aborted." << std::endl;
            return;
        }
    } else {
        if (std::filesystem::create_directory(fullPath)) {
            std::cout << "Directory created: " << fullPath << std::endl;
        } else {
            std::cerr << "Error creating directory: " << fullPath << std::endl;
        }
    }
}

void deleteFiles(const std::string& path) {
    if (fileExists(path)) {
        if (std::filesystem::remove(path)) {
            std::cout << "File deleted: " << path << std::endl;
        } else {
            std::cerr << "Error deleting file: " << path << " because you want to delete a directory" << std::endl;
        }
    } else {
        std::cerr << "File does not exist: " << path << std::endl;
    }
}

void deleteDirectory(const std::string& path) {
    if (directoryExists(path)) {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            deleteFiles(entry.path().string());
        }
        if (std::filesystem::remove(path)) {
            std::cout << "Directory deleted: " << path << std::endl;
        } else {
            std::cerr << "Error deleting directory: " << path << " because you want to delete a file" << std::endl;
        }
    } else {
        std::cerr << "Directory does not exist: " << path << std::endl;
    }
}


void listFilesAndDirectories(const std::string& path) {
    if (directoryExists(path)) {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            std::cout << entry.path().filename().string() << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Directory does not exist: " << path << std::endl;
    }
}

void printDirectoryTree(const std::string& path, const std::string& prefix = "") {
    if (directoryExists(path)) {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            auto filename = entry.path().filename().string();
            auto fullPath = entry.path().string();
            std::cout << prefix << "|-- " << filename << std::endl;
            if (std::filesystem::is_directory(fullPath)) {
                printDirectoryTree(fullPath, prefix + "    ");
            }
        }
    } else {
        std::cerr << "Directory does not exist: " << path << std::endl;
    }
}

void searchFileBFS(const std::string& startDir, const std::string& targetFile) {
    Queue queue;
    queue.enqueue(startDir);

    while (!queue.empty()) {
        std::string currentDir = queue.dequeue();
        for (const auto& entry : std::filesystem::directory_iterator(currentDir)) {
            std::string path = entry.path().string();
            if (entry.is_directory()) {
                queue.enqueue(path);
            } else if (entry.is_regular_file() && entry.path().filename() == targetFile) {
                std::cout << path << std::endl;
                return;
            }
        }
    }
    std::cout << "File not found: " << targetFile << std::endl;
}
