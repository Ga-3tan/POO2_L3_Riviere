/**
 * Name     : LAB003_Riviere
 * File     : Child.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 28.04.2021
 */

#include "Child.h"
#include "Mother.h"
#include "Father.h"

Child::Child(const std::string &name) : Person(name, false) {}

bool Child::canStayWith(const Container &c) const {
    bool motherIsHere = false;
    bool fatherIsHere = false;

    for (Person* p : c) {
        if(typeid(*p) == typeid(Mother)) motherIsHere = true;
        if(typeid(*p) == typeid(Father)) fatherIsHere = true;
    }

    // Son cannot stay with mother if father isn ot present
    return parentsPresence(motherIsHere, fatherIsHere);
}