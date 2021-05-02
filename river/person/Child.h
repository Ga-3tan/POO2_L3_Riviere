/**
 * Name     : LAB003_Riviere
 * File     : Child.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 28.04.2021
 */

#ifndef POO2_L3_RIVIERE_CHILD_H
#define POO2_L3_RIVIERE_CHILD_H

#include "Person.h"
#include "../container/Container.h"

/**
 * Represends a child (cannot drive and depends on their parents)
 */
class Child : public Person {
protected:
    /**
     * Represents a son
     * @param name The name of the son
     */
    explicit Child(const std::string& name);

public:
    /**
     * Checks if the current person can stay with
     * the people contained in the given list
     * @param c The container containing the people
     * @return True if the person can get along with the others
     */
    bool canStayWith(const Container& c) const override;

    /**
     * Returns the rule specific to the child if its a son or a daughter
     * @param mother The mother is present with the child
     * @param father  The father is present with the child
     * @return The child can stay with the given parents
     */
    virtual bool parentsPresence(bool mother, bool father) const = 0;
};

#endif //POO2_L3_RIVIERE_CHILD_H
