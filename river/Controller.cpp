#include <iostream>
#include "Controller.h"
#include "person/Person.h"
#include "person/Mother.h"
#include "person/Father.h"
#include "person/Son.h"
#include "person/Daughter.h"
#include "person/Robber.h"
#include "person/Policeman.h"

using namespace std;

Controller* Controller::getInstance() {
    if(instance == nullptr){
        instance = new Controller();
    }
    return instance;
}

Controller::Controller() : turn(0),
                           leftSide(new Bank("Gauche")),
                           rightSide(new Bank("Left")),
                           boat(new Boat("Bateau")) {
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

    // Deletes the game instance
    delete instance;
}

void Controller::showMenu() {
    cout << "p\t\t: afficher" << endl
         << "e\t\t: embarquer <nom>" << endl
         << "d\t\t: debarquer <nom>" << endl
         << "m\t\t: deplacer bateau" << endl
         << "r\t\t: reinitialiser" << endl
         << "q\t\t: quitter" << endl
         << "h\t\t: menu" << endl;
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

void Controller::nextTurn() {
    if (!turn) showMenu();
    display();
    string input;
    cin >> input;
}