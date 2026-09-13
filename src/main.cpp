#include <iostream>
#include <Todo.h>

int main() {
    Todo todo("f");
    std::cout<<GetTodo(7)<<std::endl;
    todo.CheckTodo(todo.GetID());
    return 0;
}