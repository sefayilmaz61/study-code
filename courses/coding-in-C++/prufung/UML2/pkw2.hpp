/**
 * file: pkw2.hpp
 * @brief Defines the Pkw class
 */

#ifndef PKW2_HPP
#define PKW2_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "vehicle2.hpp"

class Pkw : public Vehicle
{
private:
    double consumption;
public:
    Pkw(std::string& brand, double mileage, std::string& neededLicense, double consumption) : Vehicle(brand, mileage, neededLicense), consumption(consumption){};
    double getConsumption() const
    {
        return consumption;
    }
    void printInfo() const override;
};

#endif