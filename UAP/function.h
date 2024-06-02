#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

struct Node {
    std::string path;
    Node* next;

    Node(const std::string& path);
};

struct Queue {
    Node* front;
    Node* rear;

    Queue();

    void enqueue(const std::string& path);
    std::string dequeue();
    bool empty() const;
};

bool fileExists(const std::string& filename);
bool directoryExists(const std::string& dirname);
void createFile(const std::string& filename, const std::string& directory);
void createDirectory(const std::string& dirname, const std::string& directory);
void deleteFiles(const std::string& path);
void deleteDirectory(const std::string& path);
void listFilesAndDirectories(const std::string& path);
void printDirectoryTree(const std::string& path, const std::string& prefix);
void searchFileBFS(const std::string& startDir, const std::string& targetFile);

#endif /* FUNCTION_H */