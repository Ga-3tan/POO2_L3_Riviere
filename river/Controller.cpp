#include <iostream>
#include <vector>
#include <sstream>
#include "Controller.h"
#include "person/Mother.h"
#include "person/Father.h"
#include "person/Son.h"
#include "person/Daughter.h"
#include "person/Robber.h"
#include "person/Policeman.h"

using namespace std;

Controller::Controller() : turn(0),
                           leftSide(new Bank("Gauche")),
                           rightSide(new Bank("Left")),
                           boat(new Boat("Bateau", leftSide)) {

    // Adds all the persons on the left bank
    leftSide->add(new Father("pere"));
    leftSide->add(new Mother("mere"));
    leftSide->add(new Son("paul"));
    leftSide->add(new Son("pierre"));
    leftSide->add(new Daughter("julie"));
    leftSide->add(new Daughter("jeanne"));
    leftSide->add(new Policeman("policier"));
    leftSide->add(new Robber("voleur"));
}

Controller::~Controller() {
    // Removes every person in every bank and boat
    for (Person *p : *leftSide)
        delete p;

    for (Person *p : *rightSide)
        delete p;

    for (Person *p : *boat)
        delete p;

    // Deletes the baks and boat
    delete leftSide;
    delete rightSide;
    delete boat;
}

void Controller::showMenu() {
    cout << "p\t: afficher" << endl
         << "e <nom>\t: embarquer <nom>" << endl
         << "d <nom>\t: debarquer <nom>" << endl
         << "m\t: deplacer bateau" << endl
         << "r\t: reinitialiser" << endl
         << "q\t: quitter" << endl
         << "h\t: menu" << endl;
}

void Controller::display() {
    cout << "----------------------------------------------------------" << endl
         << *leftSide << endl
         << "----------------------------------------------------------" << endl;
    if (boat->getBank() == leftSide) {
        cout << *boat << endl
             << "==========================================================" << endl
             << "                                                          " << endl;
    } else {
        cout << "                                                          " << endl
             << "==========================================================" << endl
             << *boat << endl;
    }
    cout << "----------------------------------------------------------" << endl
         << *rightSide << endl
         << "----------------------------------------------------------" << endl;
}

string getNameFromInput(string &input) {
    return input.substr(2);
}

//Person* findPerson(Container* container, const string& name) {
//    auto it = std::find_if(container->begin(), container->end(), [&name](const Person* obj) {return obj->getName() == name;});
//    if (it == container->end()) {
//        std::cout << "Error : person not found" << std::endl;
//        return nullptr;
//    }
//    return *it;
//}

bool Controller::validateState() {
    return leftSide->validateState() && rightSide->validateState() &&
           boat->validateState();
}

bool Controller::boardPerson(Bank *bank, string name) {
    if (boat->getBank() == bank) { // if the boat on the right bank
        for (Person *p : *bank) {
            if (p->getName() == name) {
                movePerson(bank, boat, p);
                if (!validateState()) { // revert change
                    movePerson(boat, bank, p);
                    return false;
                }
                return true;
            }
        }
    }
    return false;
}

bool Controller::landPerson(string name) {
    for (Person *p : *boat) {
        if (p->getName() == name) {
            movePerson(boat, boat->getBank(), p);
            if (!validateState()) { // revert change
                movePerson(boat->getBank(), boat, p);
                return false;
            }
            return true;
        }
    }
    return false;
}

void Controller::movePerson(Container *from, Container *to, Person *person) {
    from->remove(person);
    to->add(person);
}

// TODO peut être merge avec celui du haut en mettant un paramètre at par défaut à end(), voir Container::insertAt
void Controller::movePerson(Container *from, Container *to, Person *person,
                            std::list<Person *>::iterator at /*= to->end() impossible car end retourne un const_iterator*/ ) {
    from->remove(person);
    to->insertAt(person, at);
}

void Controller::nextTurn() {
    string input;

    if (!turn++) showMenu();
    display();

    getline(cin, input, '\n');

    switch (input.at(0)) {
        case 'p':
            display();
            break;
        case 'e': {
            string name = getNameFromInput(input);
            if (boardPerson(leftSide, name)) break;
            boardPerson(rightSide, name);
            break;
        }
        case 'd': {
            string name = getNameFromInput(input);
            landPerson(name);
            break;
        }
        case 'm': {
            if (boat->size() == 0) {
                std::cout << "The boat is empty" << std::endl;
            } else if (boat->getCanMove()) {
                if (boat->getBank() == leftSide) {
                    boat->setBank(rightSide);
                } else {
                    boat->setBank(leftSide);
                }
            } else {
                std::cout << "There is no driver on the boat" << std::endl;
            }
            break;
        }
        case 'r': {
            for (Person *p : *rightSide) {
                movePerson(rightSide, leftSide, p);
            }
            for (Person *p : *boat) {
                movePerson(boat, leftSide, p);
            }
            boat->setBank(leftSide);
            break;
        }
        case 'q': {
            exit(EXIT_SUCCESS);
        }
        case 'h': {
            showMenu();
            break;
        }
        default:
            cout << "unkown command" << endl;
    }
    cin.clear();
}


