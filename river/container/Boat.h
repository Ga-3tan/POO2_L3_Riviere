/**
 * Name     : LAB003_Riviere
 * File     : Boat.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_BOAT_H
#define POO2_L3_RIVIERE_BOAT_H

#include "Container.h"
#include "Bank.h"

class Boat : public Container {
private:
    Bank& bank;
public:
    /**
     * Constructs a new boat
     * @param name The boat name
     */
    explicit Boat(const std::string &name);

    /**
     * Validates that every person in the container can
     * stay with the others without breaking any constraint
     * /!\ Also checks if there is a driver and the number of
     * people inside the boat
     * @return The boolean if the container can stay in this state
     */
    bool validateState() override;

    /**
     * Writes the container inside the given output stream
     * @param os The output stream to write on
     * @return The modified output stream
     */
    std::ostream& toStream(std::ostream& os) const override;

    /**
     * Sets the bank where the boat is
     * @param bank The current bank
     */
    void setBank(Bank& bank);

    /**
     * Gets the bank where the boat is
     * @return The current bank
     */
    Bank& getBank() const;
};

#endif //POO2_L3_RIVIERE_BOAT_H
