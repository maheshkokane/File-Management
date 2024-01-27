#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        std::cout << "File created successfully: " << filename << std::endl;
        file.close();
    } else {
        std::cerr << "Error creating file: " << filename << std::endl;
    }
}

void deleteFile(const std::string& filename) {
    if (std::remove(filename.c_str()) == 0) {
        std::cout << "File deleted successfully: " << filename << std::endl;
    } else {
        std::cerr << "Error deleting file: " << filename << std::endl;
    }
}

void copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy_file(source, destination, fs::copy_options::overwrite_existing);
        std::cout << "File copied successfully from " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error copying file: " << e.what() << std::endl;
    }
}

void moveFile(const std::string& source, const std::string& destination) {
    try {
        fs::rename(source, destination);
        std::cout << "File moved successfully from " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error moving file: " << e.what() << std::endl;
    }
}

int main() {
    std::string command;
    std::string filename, destination;

    while (true) {
        std::cout << "Enter command (create, delete, copy, move, exit): ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "Exiting program." << std::endl;
            break;
        } else if (command == "create") {
            std::cout << "Enter filename to create: ";
            std::cin >> filename;
            createFile(filename);
        } else if (command == "delete") {
            std::cout << "Enter filename to delete: ";
            std::cin >> filename;
            deleteFile(filename);
        } else if (command == "copy") {
            std::cout << "Enter source filename: ";
            std::cin >> filename;
            std::cout << "Enter destination filename: ";
            std::cin >> destination;
            copyFile(filename, destination);
        } else if (command == "move") {
            std::cout << "Enter source filename: ";
            std::cin >> filename;
            std::cout << "Enter destination filename: ";
            std::cin >> destination;
            moveFile(filename, destination);
        } else {
            std::cerr << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}