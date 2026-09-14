//
// Created by Mykola on 14.09.2026.
//

#ifndef TODOLIST_DATABASE_H
#define TODOLIST_DATABASE_H
#include <filesystem>
#include <vector>
const std::string PATH = "/Users/mykola/Desktop/database.txt";


void UpdateDatabase(std::vector<std::string> &database);
class DataBase {
public:
    static std::vector<std::string> ReadDatabase(std::fstream &file);
    static void CreateDatabase(const std::string &path);

    explicit DataBase(const std::string &path) {
        if (std::filesystem::is_empty(path)) {
            CreateDatabase(path);
        }
    }
};


#endif //TODOLIST_DATABASE_H
