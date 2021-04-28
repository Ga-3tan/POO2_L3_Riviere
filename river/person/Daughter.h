/**
 * Name     : LAB003_Riviere
 * File     : Daughter.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_DAUGHTER_H
#define POO2_L3_RIVIERE_DAUGHTER_H

#include <string>
#include "Person.h"

class Daughter : public Person {
public:
    /**
     * Represents a daughter
     * @param name The name of the daughter
     */
    explicit Daughter(const std::string& name);

    /**
     * Checks if the current person can stay with
     * the people contained in the given list
     * @param c The container containing the people
     * @return True if the person can get along with the others
     */
    bool canStayWith(const Container& c) const;
};

#endif //POO2_L3_RIVIERE_DAUGHTER_H
