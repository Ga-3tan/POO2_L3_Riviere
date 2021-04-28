/**
 * Name     : LAB003_Riviere
 * File     : Mother.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Mother.h"

Mother::Mother(const std::string &name) : Person(name, true) {}

bool Mother::canStayWith(const Container &c) const {
    // TODO
    return false;
}