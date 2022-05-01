#include "ittm.h"
#include<iostream>

using namespace ITTM;
using namespace std;

void setVals_TR(int currentState, char currentCell, char newContent, int moveDirection, int nextState) {
    if (currentState < -1 || nextState < -1) {
        throw std::invalid_argument("Received invalid transition rule state");
    }
    if (moveDirection < -1 || moveDirection > 1) {
        throw std::invalid_argument("Received invalid transition rule move direction.");
    }
    this->currentState = currentState;
    this->currentCell = currentCell;
    this->newContent = newContent;
    this->moveDirection = moveDirection;
    this->nextState = nextState;
}