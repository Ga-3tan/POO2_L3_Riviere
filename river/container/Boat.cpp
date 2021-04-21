/**
 * Name     : LAB003_Riviere
 * File     : Boat.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Boat.h"
#include <iostream>

Boat::Boat(const std::string &name) : Container(name) {}

bool Boat::validateState() {

}

std::ostream& Boat::toStream(std::ostream& os) const {

}

void Boat::setBank(Bank& bank) {
    this->bank = bank;
}

Bank& Boat::getBank() const {
    return this->bank;
}