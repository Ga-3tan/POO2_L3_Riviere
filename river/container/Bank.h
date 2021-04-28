/**
 * Name     : LAB003_Riviere
 * File     : Bank.h
 * Authors  : Gaétan Zwick, Marco Maziero
 * Date     : 14.04.2021
 */

#ifndef POO2_L3_RIVIERE_BANK_H
#define POO2_L3_RIVIERE_BANK_H

#include "Container.h"

class Bank : public Container {
public:
    /**
     * Constructs a new river bank
     * @param name The bank name
     */
    explicit Bank(const std::string &name);

    /**
     * Writes the container inside the given output stream
     * @param os The output stream to write on
     * @return The modified output stream
     */
    std::ostream& toStream(std::ostream& os) const override;
};

#endif //POO2_L3_RIVIERE_BANK_H
