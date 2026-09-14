//
// Created by Mykola on 11.09.2026.
//

#include "Todo.h"
#include <fstream>
#include <vector>
#include <database/database.h>

int Todo::elementsCount = 0;

void Todo::CheckTodo(const int& identifier) {
    std::string target = "<" + std::to_string(identifier) + ">";
    std::fstream file(PATH);
    std::vector<std::string> buffer = DataBase::ReadDatabase(file);
    for (std::string &line : buffer) {
        if (!line.contains(target)) {
            continue;
        }
        line[line.size() - 2] = '+';
        UpdateDatabase(buffer);
        return;
    }

}

void Todo::SyncID() {
    std::fstream file(PATH,std::ios::in);
    std::vector<std::string> copy = DataBase::ReadDatabase(file);
    std::string line = copy[0];
    if (!line.empty() && line.back() == ';') {
        line.pop_back();
    }
    id = elementsCount = stoi(line)+1;
    file.close();
    UpdateDatabase(copy);

}



void Todo::CreateTodo(const std::string &line) {
    note = line;
    std::ofstream file;
    file.open(PATH, std::ios::out | std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("File is not opened");
    }
    file<<'<'<<id<<'>'<<'\t'<<line<<';'<<'\t'<<"-;"<<'\n';
    file.close();
}


std::string GetTodo(const int &id) {
    std::string line;
    std::fstream file(PATH, std::ios_base::in);
    while (std::getline(file,line)) {
        if (!line.contains("<" + std::to_string(id)+ ">")) {
           continue;
        }
        const auto start = line.find('\t') + 1;
        const auto end = line.find(';',start);


        return line.substr(start,end - start);
    }
    return {};
}
