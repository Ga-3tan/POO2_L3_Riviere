/**
 * Name     : LAB003_Riviere
 * File     : Person.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Person.h"

Person::Person(std::string name, bool isDriver)
: name(std::move(name)), isDriver(isDriver) {}

bool Person::canDrive() const {
    return isDriver;
}

std::string Person::getName() const {
    return name;
}

bool Person::operator==(const Person &rhs) const {
    return name == rhs.name &&
           isDriver == rhs.isDriver;
}

bool Person::operator!=(const Person &rhs) const {
    return !(rhs == *this);
}

