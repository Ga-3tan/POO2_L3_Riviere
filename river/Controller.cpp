#include <iostream>
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

void Controller::nextTurn() {
    // TODO
    if (!turn) showMenu();
    display();
    Person* p = *leftSide->begin();
    leftSide->remove(p);
    rightSide->add(p);
    string input;
    cin >> input;
}