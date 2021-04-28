/**
 * Name     : LAB003_Riviere
 * File     : Container.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_CONTAINER_H
#define POO2_L3_RIVIERE_CONTAINER_H

#include <iterator>
#include "../person/Person.h"
#include <list>
#include <string>

class Container;

/**
 * Allows to write the container inside an output stream
 * @param os The output stream to write on
 * @param container The container to write
 * @return The modified output stream
 */
std::ostream& operator<<(std::ostream& os, const Container& container);

class Container {
private:
    std::string name;
    std::list<Person*> people;
protected:
    /**
     * Creates a container with a given name
     * @param name
     */
    Container(std::string name);
public:
    /**
     * Returns the begin() iterator of the people list
     * @return The begin() iterator
     */
    std::list<Person*>::const_iterator begin() const;

    /**
     * Returns the end() iterator of the people list
     * @return The end() iterator
     */
    std::list<Person*>::const_iterator end() const;

    /**
     * Validates that every person in the container can
     * stay with the others without breaking any constraint
     * @return The boolean if the container can stay in this state
     */
    virtual bool validateState();

    /**
     * Writes the container inside the given output stream
     * @param os The output stream to write on
     * @return The modified output stream
     */
    virtual std::ostream& toStream(std::ostream& os) const = 0;

    /**
     * Adds a person to the list
     * @param person The person to add
     * @return The modified container
     */
    Container& add(Person* person);

    /**
     * Removes a person from the list
     * @param person The person to remove
     * @return The modified container
     */
    Container& remove(Person* person);

    /**
     * Gives the current container size
     */
    size_t size() const;
};

#endif //POO2_L3_RIVIERE_CONTAINER_H
