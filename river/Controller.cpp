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
    for (Person* p : *leftSide)
        delete p;

    for (Person* p : *rightSide)
        delete p;

    for (Person* p : *boat)
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
         << "----------------------------------------------------------" << endl
         << *boat << endl
         << "==========================================================" << endl
         << "----------------------------------------------------------" << endl
         << *rightSide << endl
         << "----------------------------------------------------------" << endl;
}

string getNameFromInput(string& input) {
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

string Controller::saveState() {
    *boatSave = *boat;
}

bool Controller::validateState() {
    return leftSide->validateState() && rightSide->validateState() && boat->validateState();
}

bool Controller::boardPerson(Bank* bank, string name) {
    for (Person* p : *bank) {
        if (p->getName() == name) {
            movePerson(bank, boat, p);
            if (!validateState()) { // revert change
                movePerson(boat, bank, p);
                return false;
            }
            return true;
        }
    }
    return false;
}

bool Controller::landPerson(Bank* bank, string name) {
    for (Person* p : *bank) {
        if (p->getName() == name) {
            movePerson(boat, bank, p);
            if (!validateState()) { // revert change
                movePerson(bank, boat, p);
                return false;
            }
            return true;
        }
    }
    return false;
}

void Controller::movePerson(Container* from, Container* to, Person* person) {
    from->remove(person);
    to->add(person);
}

void Controller::nextTurn() {
    string input;

    if (!turn++) showMenu();
    display();

    getline(cin, input, '\n');

    switch (input.at(0)) {
        case 'p': display(); break;
        case 'e': {
            string name = getNameFromInput(input);
            if (boardPerson(leftSide,name)) break;
            boardPerson(rightSide, name);
            break;
        }
        case 'd': {
            string name = getNameFromInput(input);
            if (landPerson(leftSide,name)) break;
            landPerson(rightSide, name);
            break;
        }
        case 'm': {
            if (boat->getBank() == leftSide) {
                boat->setBank(rightSide);
            } else {
                boat->setBank(leftSide);
            }
            break;
        }
        case 'r': {
            for (Person* p : *rightSide) {
                movePerson(rightSide,leftSide,p);
            }
            for (Person* p : *boat) {
                movePerson(boat, leftSide,p);
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
        default: cout << "unkown command" << endl;
    }
    cin.clear();
}


