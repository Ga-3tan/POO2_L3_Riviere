/**
 * Name     : LAB003_Riviere
 * File     : Person.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_PERSON_H
#define POO2_L3_RIVIERE_PERSON_H

#include <string>
#include "../container/Container.h"

class Person {
private:
    std::string name;
    bool isDriver;
protected:
    /**
     * Represents a person
     * @param name The name of the person
     * @param isDriver Boolean telling if the person can drive
     */
    Person(std::string name, bool isDriver) : name(name), isDriver(isDriver) {}

public:
    /**
     * Gives the name of the person
     * @return The name
     */
    std::string getName() const;

    /**
     * Returns if the person is a boat driver or not
     * @return The boolean telling whether the person can drive or not
     */
    virtual bool canDrive() const;

    /**
     * Checks if the current person can stay with
     * the people contained in the given list
     * @param c The container containing the people
     * @return True if the person can get along with the others
     */
    virtual bool canStayWith(const Container& c) const = 0;
};

#endif //POO2_L3_RIVIERE_PERSON_H
