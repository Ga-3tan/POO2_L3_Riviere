/**
 * Name     : LAB003_Riviere
 * File     : River.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "River.h"
#include "Controller.h"

void River::start() {
    //Controller* riverGame = Controller::getInstance();
    Controller riverGame;

    while (true) {
        riverGame.nextTurn();
    }
}

