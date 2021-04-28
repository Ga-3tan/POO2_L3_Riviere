/**
 * Name     : LAB003_Riviere
 * File     : Policeman.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Policeman.h"

Policeman::Policeman(const std::string &name) : Person(name, true) {}

bool Policeman::canStayWith(const Container &c) const {
    return true;
}