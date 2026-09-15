//
// Created by Mykola on 14.09.2026.
//

#ifndef TODOLIST_DATABASE_H
#define TODOLIST_DATABASE_H
#include <filesystem>
#include <vector>
#include <fstream>

const std::string PATH = "/Users/mykola/Desktop/database.txt";
static std::fstream file_;


static std::fstream GetDataBase() {
    return std::move(file_);
}
void UpdateDatabase(std::vector<std::string> &database);
class DataBase {
public:
    static std::vector<std::string> ReadDatabase(std::fstream &file);
    static void CreateDatabase(std::fstream &file);

    explicit DataBase(const std::string &path) {
        std::fstream file(path);
        file_ = std::move(file);
        if (std::filesystem::is_empty(path)) {
            CreateDatabase(file_);
        }
    }
};


#endif //TODOLIST_DATABASE_H
