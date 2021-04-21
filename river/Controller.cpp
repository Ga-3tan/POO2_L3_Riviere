#include "Controller.h"

Controller* Controller::getInstance() {
    if(instance == nullptr){
        instance = new Controller();
    }
    return instance;
}

Controller::~Controller() {
    delete instance;
    // TODO
}

void Controller::showMenu() {
    // TODO
}

void Controller::display() {
    // TODO
}

void Controller::nextTurn() {
    // TODO
}
