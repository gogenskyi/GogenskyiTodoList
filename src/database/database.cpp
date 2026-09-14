//
// Created by Mykola on 14.09.2026.
//

#include "database.h"
#include <fstream>
#include "Todo.h"

void UpdateDatabase(std::vector<std::string> &database){
    std::fstream f(PATH, std::ios::out);
    database[0] = std::to_string(Todo::elementsCount) + ';';
    for (const auto & i : database) {
        f<<i<<'\n';
    }
    f.close();
}

std::vector<std::string> DataBase::ReadDatabase(std::fstream &file) {
    if (!file.is_open())
        file.open(PATH,std::ios::in | std::ios::out);
    std::string buffer;
    std::vector<std::string> copy;
    while (std::getline(file, buffer)) {
        copy.push_back(buffer);
    }
    return copy;
}

void DataBase::CreateDatabase(const std::string &path) {
    std::ofstream file(path);
    file<<"0;"<<std::endl;
}
