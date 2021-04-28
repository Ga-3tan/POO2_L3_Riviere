/**
 * Name     : LAB003_Riviere
 * File     : Robber.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Robber.h"

Robber::Robber(const std::string &name) : Person(name, false) {}

bool Robber::canStayWith(const Container &c) const {
    return false;
}