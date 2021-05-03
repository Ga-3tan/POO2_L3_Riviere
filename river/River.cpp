/**
 * Name     : LAB003_Riviere
 * File     : River.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "River.h"
#include "Controller.h"

void River::start() {

    // Initial display
    Controller::getInstance().showMenu();
    Controller::getInstance().display();
    std::cout << std::endl;

    while (!Controller::getInstance().nextTurn());
}