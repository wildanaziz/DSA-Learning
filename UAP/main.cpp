#include <iostream>
#include "function.h"

int main() {
    while (true) {
        std::cout << "--- mkfile and mkdir generator ---" << std::endl;
        std::cout << "1. Make File\n2. Make Directory\n3. Delete File \n4. Delete Directory\n5. List Files and Directories\n6. Print Directory Tree\n7. Search Files\n8. Exit\n";
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        std::string filename, dirname, directory, path;

        switch (choice) {
            case 1:
                std::cout << "Enter the file name: ";
                std::getline(std::cin, filename);
                std::cout << "Where do you want to create the file? (default is current directory): ";
                std::getline(std::cin, directory);
                if (directory.empty()) {
                    std::cout << "Directory was set to current directory." << std::endl;
                    directory = ".";
                }
                std::cout << "Creating file in " << directory << std::endl;
                createFile(filename, directory);
                break;
            case 2:
                std::cout << "Enter the directory name: ";
                std::getline(std::cin, dirname);
                std::cout << "Where do you want to create the directory? (default is current directory): ";
                std::getline(std::cin, directory);
                if (directory.empty()) {
                    directory = ".";
                }
                std::cout << "Creating directory in " << directory << std::endl;
                createDirectory(dirname, directory);
                break;
            case 3:
                printDirectoryTree(".", "");
                std::cout << "Enter the path to delete: ";
                std::getline(std::cin, path);
                deleteFiles(path);
                break;
            case 4:
                printDirectoryTree(".", "");
                std::cout << "Enter the path to delete: ";
                std::getline(std::cin, path);
                deleteDirectory(path);
                break;
            case 5:
                std::cout << "Enter the directory to list (default is current directory): ";
                std::getline(std::cin, directory);
                if (directory.empty()) {
                    directory = ".";
                }
                listFilesAndDirectories(directory);
                break;
            case 6:
                std::cout << "Enter the directory to print likes tree (default is current directory): ";
                std::getline(std::cin, directory);
                if (directory.empty()) {
                    directory = ".";
                }
                printDirectoryTree(".", "");

                break;
            case 7:
                std::cout << "Enter the file name to search: ";
                std::getline(std::cin, filename);
                if (directory.empty()) {
                    directory = ".";
                }
                searchFileBFS(directory, filename);
                break;
            case 8:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}
