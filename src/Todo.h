//
// Created by Mykola on 11.09.2026.
//

#ifndef TODOLIST_TODO_H
#define TODOLIST_TODO_H
#include <string>
#include <vector>

class Todo {
    std::string note;
    int id{};
    bool checked = false;
    void SyncID();
public:
    static int elementsCount;
    int GetID() const {
        return id;
    }

    explicit Todo(const std::string &line) {
        SyncID();
        CreateTodo(line);
    }

    static void CheckTodo(const int& identifier);
    void CreateTodo(const std::string& line);
    std::string GetNote() {
        if (!note.empty())
            return note;
        return "";
    }
};

std::string GetTodo(const int &id);

#endif //TODOLIST_TODO_H
