/**
 * Name     : LAB003_Riviere
 * File     : Father.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_FATHER_H
#define POO2_L3_RIVIERE_FATHER_H

#include <string>
#include "Person.h"

class Father : public Person {
public:
    /**
     * Represents a father
     * @param name The name of the father
     */
    Father(const std::string& name) : Person(name, true) {}

    /**
     * Checks if the current person can stay with
     * the people contained in the given list
     * @param c The container containing the people
     * @return True if the person can get along with the others
     */
    bool canStayWith(const Container& c) const;
};

#endif //POO2_L3_RIVIERE_FATHER_H
