/**
 * Name     : LAB003_Riviere
 * File     : Controller.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_CONTROLLER_H
#define POO2_L3_RIVIERE_CONTROLLER_H

#include <cstddef>
#include "container/Bank.h"
#include "container/Boat.h"

class Controller {
private:
    std::size_t turn;
    Bank* leftSide;
    Bank* rightSide;
    Boat* boat;

public:
    /**
     * Creates a new controller with its attributes
     */
    Controller();

    /**
     * Deletes the dynamically attributes pointers
     */
    ~Controller();

    /**
     * Shows the game menu
     */
    void showMenu();

    /**
     * Displays the game state
     */
    void display();

    /**
     * Starts the next turn
     */
    void nextTurn();

    /**
     * Forbidden function, the class is a singleton
     * @param c The controller to copy
     */
    Controller(const Controller& c) = delete;

    /**
     * Forbidden function, the class is a singleton
     * @param c The controller to copy
     * @return The current controller
     */
    Controller& operator=(const Controller& c) = delete;
};

#endif //POO2_L3_RIVIERE_CONTROLLER_H
