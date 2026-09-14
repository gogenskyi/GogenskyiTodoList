#include <iostream>
#include <Todo.h>

int main() {
    const Todo todo("f1");
    std::cout<<GetTodo(7)<<std::endl;
    Todo::CheckTodo(todo.GetID());
    return 0;
}