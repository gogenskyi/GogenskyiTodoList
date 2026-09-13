//
// Created by Mykola on 11.09.2026.
//

#include "Todo.h"
#include <fstream>
#include <iostream>
#include <vector>

const std::string PATH = "/Users/mykola/Desktop/database.txt";

std::vector<std::string> Todo::ReadDatabase(std::fstream &file) {
    if (!file.is_open())
        file.open(PATH,std::ios::in | std::ios::out);
    std::string buffer;
    std::vector<std::string> copy;
    while (std::getline(file, buffer)) {
        copy.push_back(buffer);
    }
    return copy;
}


void Todo::CheckTodo(const int& identeficator) {
    std::fstream file(PATH);
    std::vector<std::string> buffer = ReadDatabase(file);
    for (int i = 1;i < buffer.size();i++) {
        if (buffer[i].contains('<' + std::to_string(identeficator) + '>')) {
            for (int a = 0;true;a++) {
                if (buffer[i][a] == '-') {
                    buffer[i][a] = '+';
                    UpdateDatabase(buffer);
                    return;
                }
            }
        }
    }
    UpdateDatabase(buffer);
}

void Todo::SyncID() {
    std::fstream file(PATH,std::ios::in);
    std::string buffer;
    std::vector<std::string> copy = {};
    std::string syncedID;
    int count = 0;
    while (std::getline(file,buffer)) {
        copy.push_back(buffer);
        if (syncedID.empty()) {
            for (int i = 0;true;i++) {
                if (isdigit(buffer[i])) {
                    syncedID += buffer[i];
                }
                if (buffer[i] == ';') {
                    id = std::stoi(syncedID) + 1;
                    break;
                }
            }
        }
        count++;
    }
    file.close();
    UpdateDatabase(copy);

}

void Todo::UpdateDatabase(std::vector<std::string> &database) const {
    std::fstream f(PATH, std::ios::out);
    database[0] = std::to_string(id) + ';';
    for (int i = 0; i < database.size();i++) {
        f<<database[i]<<'\n';
    }
    f.close();
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
    std::string result;
    std::string line;
    std::fstream file(PATH, std::ios_base::in);
    std::string stringID;
    while (std::getline(file,line)){
        for (int i = 0; line[i] != '\t';i++) {
            if (isdigit(line[i])) {
                stringID += line[i];
                if (stringID == std::to_string(id)) {
                    while (line[i] != ';') {
                        i++;
                        if (line[i] != '\t' && line.size() - 1 != i)
                            result += line[i];
                    }
                }
                stringID.clear();
                break;
            }
        }

    }
    file.close();
    return result;
}
