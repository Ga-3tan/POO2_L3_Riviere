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

/**
 * Manages all the game mechanics, is singleton
 */
class Controller {
private:
    std::size_t turn;
    std::list<Person*> players;
    Bank* leftSide;
    Bank* rightSide;
    Boat* boat;

    /**
     * Creates a new controller with its attributes
     */
    Controller();

    /**
     * Finds a person by its textual name
     * @param name The person name as a string
     * @return The person found otherwise nullptr
     */
    Person* findPersonByName(const std::string& name) const;

    /**
     *Finds the container where the person is
     * @param person The person to analyse
     * @return The container found otherwise nullptr
     */
    Container* findPersonContainer(Person* person) const;

    /**
     * Validates the current state of all containers
     * @return True if all the people in containers can stay together
     *         false if there is a constraint not respected
     */
    bool validateState() const;

    /**
     * Boards a person on the boat
     * @param p The person to board
     * @param currentContainer The current container where the person is
     * @return True if the person has been moved, false otherwise
     */
    bool boardPerson(Person* p, Container* currentContainer);

    /**
     * Lands a person from the boat
     * @param p The person to land
     * @param currentContainer The current container where the person is
     * @return True if the person has been moved, false otherwise
     */
    bool landPerson(Person* p, Container* currentContainer);

    /**
     * Tries to move a person. If the constraints are not respected,
     * the person is replaced in its original container and nothing is moved
     * @param from The source container
     * @param to The destination container
     * @param person The person to move
     * @return True if the person was successfully moved, false otherwise
     */
    bool tryMovePerson(Container *from, Container *to, Person *person) const;

    /**
     * return the name from the input, checks if the size of the input is > 2,
     * then remove the command char with the space and return the name
     * @param input The input with a name from the user
     * @return A string of the name from the user input
     */
    static std::string getNameFromInput(std::string &input);

public:

    /**
     * Retrieves the singleton instance of the game class
     * @return
     */
    static Controller& getInstance();

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
     * @return True if game is over
     */
    bool nextTurn();

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
