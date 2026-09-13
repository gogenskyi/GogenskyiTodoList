//
// Created by Mykola on 11.09.2026.
//

#ifndef TODOLIST_TODO_H
#define TODOLIST_TODO_H
#include <string>
#include <vector>

class Todo {
    std::string note;
    int id;
    bool checked = false;
    void SyncID();
    static std::vector<std::string> ReadDatabase(std::fstream &file);
    void UpdateDatabase(std::vector<std::string> &database) const;
public:
    int GetID() const {
        return id;
    }
    Todo(const std::string &line) {
        SyncID();
        CreateTodo(line);
    }

    void CheckTodo(const int& identeficator);
    void CreateTodo(const std::string& line);
    std::string GetNote() {
        if (!note.empty())
            return note;
        return "";
    }
};

std::string GetTodo(const int &id);

#endif //TODOLIST_TODO_H
