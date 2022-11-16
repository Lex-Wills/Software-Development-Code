#include <iostream>
#include "GameObject.h"
#include "wordwrap.h"

GameObject::GameObject(const string keyword, const string description) :
        keyword(keyword), description(description) {};

void GameObject::describe() const {
    std::cout << this->keyword << " (" << this->description << ")" << std::endl;
}

string GameObject::getKeyword() {
    return this->keyword;
}

string GameObject::getDescription() {
    return this->description;
}