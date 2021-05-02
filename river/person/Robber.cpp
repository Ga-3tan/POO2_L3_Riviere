/**
 * Name     : LAB003_Riviere
 * File     : Robber.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Robber.h"
#include "Policeman.h"

Robber::Robber(const std::string &name) : Person(name, false) {}

bool Robber::canStayWith(const Container &c) const {
    bool isPolicemanHere = false;

    // Iterates through the list of Person
    for (Person* p : c){
        if(typeid(*p) == typeid(Policeman)) isPolicemanHere = true;
    }

    // If there is no policeman, cannot be with other members
    if(c.size() > 1 && !isPolicemanHere) {
        std::cout << "Voleur seul avec la famille sans le policier" << std::endl;
        return false;
    }
    return true;
}