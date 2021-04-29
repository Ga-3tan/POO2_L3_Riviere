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
    if (size() < 1) {
        std::cout << "The boat is empty" << std::endl;
        return false;
    }
    if (size() > 2) {
        std::cout << "There is too much people on the boat" << std::endl;
        return false;
    }

    /* check if there is at least one driver */
    if (size() == 2) {
        bool hasDriver = false;
        for (Person* p : people) if (p->canDrive()) hasDriver = true;
        if (!hasDriver) {
            std::cout << "There is no driver on the boat" << std::endl;
            return false;
        }
    }

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