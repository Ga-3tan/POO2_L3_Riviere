/**
 * Name     : LAB003_Riviere
 * File     : Daughter.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Daughter.h"

Daughter::Daughter(const std::string &name) : Child(name) {}

bool Daughter::parentsPresence(bool mother, bool father) const {
    return !(father && !mother);
}