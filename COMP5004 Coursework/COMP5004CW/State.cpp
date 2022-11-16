//
// Created by DrMark on 10/2/2017.
//

#include <iostream>
#include <iterator>
#include <fstream>
#include "State.h"
#include "Room.h"
#include <vector>


/**
 * Current state of the game.
 */

/**
 * Display the description of the room the player is in. */

void State::announceLoc() const {
    this->currentRoom->describe();
    std::list<GameObject*> roomObjects = this->currentRoom->objects;
/**
 * if statement describing if there is an object in the room
 */
    if (roomObjects.size() > 0) {
        std::cout << "You find the following objects in the room:" << std::endl;
        roomObjects.front()->describe();
    }
}

/**
 * Constructor.
 * @param startRoom Pointer to the room to start in.
 */
State::State(Room *startRoom) : currentRoom(startRoom) {};

/**
 * Move to a specified room and print its description.
 * @param target Pointer to the room to move to.
 */
void State::goTo(Room *target) {
    this->currentRoom = target;
    this->announceLoc();
}

/**
 * Return a pointer to the current room.
 * @return Pointer to the current room.
 */
Room* State::getCurrentRoom() const {
    return this->currentRoom;
}

void State::addToInventory(GameObject* object) {
    this->inventory.push_back(object);
}

void State::printInventory(){
    std::cout << "[";
    for(GameObject* object : this->inventory) {
        std::cout << object->getKeyword();
    }
    std::cout << "]" << std::endl;
}

void State::dropFromInventory(const string& keywordToDrop) {
    for(GameObject* object : this->inventory) {
        if(object->getKeyword() == keywordToDrop) {
          inventory.remove(object);
          getCurrentRoom()->objects.push_back(object);
          std::cout << "Dropped " << keywordToDrop << std::endl;
        }
    }
}

/**
 * Gives description of object in the inventory
 */
 void State::examineObject(const string & objectDescription) {
     std::cout << "The object's description is... ";
    for(GameObject* description : this->inventory) {
        std::cout << description->getDescription();
    }
     std::cout << "." << std::endl;
 }

/**
 * Pick up object
 */
void State::pickUpObject() {
    GameObject* object = State::getCurrentRoom()->objects.front();
    State::addToInventory(object);
    State::getCurrentRoom()->objects.pop_front();
    std::cout << "Picked up " << object->getKeyword() << std::endl;
}

void State::saveGame() {
    std::cout << "You choose to exit! Do you wish to save your current progress? (Y/N)";
    char choice;
    std::cin >> choice;
    if (choice == 'Y') {
        std::string save;
        std::cout << "Enter the name of the file you want to save your progress in: ";
        std::cin >> save;
        std::ofstream file_input(save);
    }
    std::string filename = "saved.txt";
    std::ofstream file_input(filename, std::ios::app);

    // check whether the file is open
    if(file_input.is_open())
    {
        std::cout << "the file is open" << std::endl;
    }
    else
    {
        std::cout << "the file is closed" << std::endl;
    }




    // close the file stream connection
    file_input.close();

    // check whether the file is open
    if(file_input.is_open())
    {
        std::cout << "the file is open" << std::endl;
    }
    else
    {
        std::cout << "the file is closed" << std::endl;
    }
}

void State::loadGame() {
    std::cout << "Load a saved file or start a new game? (L/N)";
    char choice;
    std::cin >> choice;
    if (choice == 'L'){
        std::string filename;
        std::cout << "Enter the name of the file";
        std::cin >> filename;
        std::ifstream file_input(filename);
    }
}

/**
 * Check whether there is an object on the ground
 */
    bool State::isObjectOnGround() {
        return State::getCurrentRoom()->objects.size() > 0;
    }