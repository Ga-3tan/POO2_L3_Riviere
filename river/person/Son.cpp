/**
 * Name     : LAB003_Riviere
 * File     : Son.cpp
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#include "Son.h"

Son::Son(const std::string &name) : Child(name) {}

bool Son::parentsPresence(bool mother, bool father) const {
    return !(mother && !father);
}