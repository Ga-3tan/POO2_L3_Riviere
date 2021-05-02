/**
 * Name     : LAB003_Riviere
 * File     : Son.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_SON_H
#define POO2_L3_RIVIERE_SON_H

#include <string>
#include "Child.h"

/**
 * Represents a son (cannot be left alone with the mother)
 */
class Son : public Child {
public:
    /**
     * Represents a son
     * @param name The name of the son
     */
    explicit Son(const std::string& name);

    /**
     * Returns the rule specific to the child if its a son or a daughter
     * @param mother The mother is present with the child
     * @param father  The father is present with the child
     * @return The child can stay with the given parents
     */
    bool parentsPresence(bool mother, bool father) const override;
};

#endif //POO2_L3_RIVIERE_SON_H
