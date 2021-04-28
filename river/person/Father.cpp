/**
 * Name     : LAB003_Riviere
 * File     : Father.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Father.h"

Father::Father(const std::string &name) : Person(name, true) {}

bool Father::canStayWith(const Container &c) const {
    // TODO
    return false;
}