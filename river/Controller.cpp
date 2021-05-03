#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Controller.h"
#include "person/Mother.h"
#include "person/Father.h"
#include "person/Son.h"
#include "person/Daughter.h"
#include "person/Robber.h"
#include "person/Policeman.h"

using namespace std;

Controller& Controller::getInstance() {
    static Controller instance;
    return instance;
}

Controller::Controller() : turn(0),
                           leftSide(new Bank("Gauche")),
                           rightSide(new Bank("Droite")),
                           boat(new Boat("Bateau", leftSide)) {

    // Creates all the game players
    players.push_back(new Father("pere"));
    players.push_back(new Mother("mere"));
    players.push_back(new Son("paul"));
    players.push_back(new Son("pierre"));
    players.push_back(new Daughter("julie"));
    players.push_back(new Daughter("jeanne"));
    players.push_back(new Policeman("policier"));
    players.push_back(new Robber("voleur"));

    // Adds all the persons on the left bank
    for (Person* p : players)
        leftSide->add(p);
}

Controller::~Controller() {
    // Removes every player
    for (Person* p : players)
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
    if (input.size() < 2) return "";
    return input.substr(2);
}

Person* Controller::findPersonByName(const string& name) const {
    // Searches in the list of persons
    auto it = std::find_if(players.begin(), players.end(),
               [&name](const Person* p) {return p->getName() == name;});
    if (it == players.end()) {
        cout << "La personne " << name << " n'existe pas" << endl;
        return nullptr;
    }
    return *it;
}

Container* Controller::findPersonContainer(Person* person) const {
    vector<Container*> containers{leftSide, rightSide, boat};
    for (Container* c : containers) {
        auto it = std::find(c->begin(), c->end(), person);
        if (it != c->end()) return c; // Returns the container
    }

    // Person not found in any container
    cout << "La personne " << person->getName() << " n'est pas sur le jeu" << endl;
    return nullptr;
}

bool Controller::validateState() const{
    return leftSide->validateState() && rightSide->validateState() &&
           boat->validateState();
}

bool Controller::boardPerson(Person* p, Container* currentContainer) {
    // checks if person is already on the boat
    if (currentContainer == boat) {
        cout << "La personne " << p->getName() <<
             " est deja sur le bateau" << endl;
        return false;
    }

    // Checks if the boat is on the correct bank before boarding
    if (boat->getBank() != currentContainer) {
        cout << "La personne " << p->getName() <<
        " n'est pas sur la meme rive que le bateau" << endl;
        return false;
    }

    // Tries to make the move
    return tryMovePerson(currentContainer, boat, p);
}

bool Controller::landPerson(Person* p, Container* currentContainer) {
    // Checks if the person is on the boat
    if (currentContainer != boat) {
        cout << "La personne " << p->getName() <<
        " n'est pas sur le bateau" << endl;
        return false;
    }

    // Tries to make the move
    return tryMovePerson(boat, boat->getBank(), p);
}

bool Controller::tryMovePerson(Container *from,
                               Container *to,
                               Person *person) const {
    // Tries to move the person on the boat and checks the containers states
    from->remove(person);
    to->add(person);

    // Validates the states
    if (validateState())
        return true;

    // Illegal state, reverts the changes
    to->remove(person);
    from->add(person);
    return false;
}

bool Controller::nextTurn() {
    // Takes user input
    cout << turn << "> ";
    string input;
    getline(cin, input, '\n');
    cin.clear();

    // Input validation
    if (input.empty()) return false;

    // Retrieves the person and its container
    Person* person = nullptr;
    Container* currentContainer = nullptr;
    if (input.at(0) == 'e' || input.at(0) == 'd') {
        // Retrieves the person
        person = findPersonByName(getNameFromInput(input));
        if (person == nullptr) return false;

        // Retrieves the person current container
        currentContainer = findPersonContainer(person);
        if (currentContainer == nullptr) return false;
    }

    // Validates the command input
    switch (input.at(0)) {
        case 'p':
            display();
            return false;
        case 'e':
            if (!boardPerson(person, currentContainer)) return false;
            break;
        case 'd':
            if (!landPerson(person, currentContainer)) return false;
            break;
        case 'm':
            if (boat->hasDriver()) {
                if (boat->getBank() == leftSide)
                    boat->setBank(rightSide);
                else
                    boat->setBank(leftSide);
            } else {
                std::cout << "Aucun conducteur present sur le bateau" << std::endl;
                return false;
            }
            break;
        case 'r':
            // Clears all containers
            leftSide->clear();
            rightSide->clear();
            boat->clear();

            // Adds all the persons on the left bank
            for (Person* p : players)
                leftSide->add(p);

            turn = -1;
            break;
        case 'q':
            exit(EXIT_SUCCESS);
        case 'h':
            showMenu();
            cout << endl;
            return false;
        default:
            cout << "Commande inconnue" << endl;
            return false;
    }

    display();
    cout << endl;
    ++turn;

    // Checks end of game
    if (rightSide->size() == players.size()) {
        cout << "Partie terminee, felicitations !" << endl;
        return true;
    }

    // Game not over, continues
    return false;
}