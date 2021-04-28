/**
 * Name     : LAB003_Riviere
 * File     : Son.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Son.h"

Son::Son(const std::string &name) : Person(name, false) {}

bool Son::canStayWith(const Container &c) const {
    // TODO
    return false;
}