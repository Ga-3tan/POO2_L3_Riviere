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
    for (auto it = c.begin(); it != c.end(); ++it) {
        if(typeid(*it) == typeid(Policeman)) isPolicemanHere = true;
    }

    // If there is no policeman, cannot be with other members
    if(c.size() && !isPolicemanHere) return false;
    return true
}