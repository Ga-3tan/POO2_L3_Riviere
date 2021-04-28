/**
 * Name     : LAB003_Riviere
 * File     : Daughter.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Daughter.h"

Daughter::Daughter(const std::string &name) : Person(name, false) {}

bool Daughter::canStayWith(const Container &c) const {
    // TODO
    return false;
}