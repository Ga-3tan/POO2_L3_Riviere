/**
 * Name     : LAB003_Riviere
 * File     : Boat.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Boat.h"
#include <iostream>

Boat::Boat(const std::string &name, Bank* bank) : Container(name), bank(bank) {}

bool Boat::validateState() {
    /* needs at least 1 person and maximum 2 people */
    if (size() < 1 || size() > 2) return false;

    /* check if there is at least one driver */
    bool hasDriver = false;
    for (Person* p : people) if (p->canDrive()) hasDriver = true;
    if (!hasDriver) return false;

    /* check if the people onboard can stay together */
    if (!Container::validateState()) return false;

    /* all tests passed */
    return true;
}

std::ostream& Boat::toStream(std::ostream& os) const {
    return Container::toStream(os << name << ": < ") << " >";
}

void Boat::setBank(Bank* bank) {
    this->bank = bank;
}

Bank* Boat::getBank() const {
    return this->bank;
}