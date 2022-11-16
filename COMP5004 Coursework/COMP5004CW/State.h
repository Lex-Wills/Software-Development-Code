//
// Created by DrMark on 10/2/2017.
//

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H

#include "Room.h"

class State {
    Room *currentRoom;
public:
    explicit State(Room *startRoom);
    void goTo(Room *target);
    void announceLoc() const;
    Room* getCurrentRoom() const;

    std::list<GameObject*> inventory;

    void addToInventory(GameObject* object);

    void pickUpObject();

    void printInventory();

    void dropFromInventory(const string& keyword);

    void examineObject(const string& description);

    void saveGame();

    void loadGame();

    bool isObjectOnGround();
};

#endif //TEXTADV_STATE_H