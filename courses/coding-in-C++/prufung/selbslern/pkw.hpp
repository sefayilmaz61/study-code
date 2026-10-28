/**
 * file: pkw.hpp
 * @brief Defines pkw class
 */

#ifndef PKW_HPP
#define PKW_HPP

#include <string>
#include <iostream>
#include "vehicle.hpp"
#include "driver.hpp"

class Pkw : public Vehicle{
private:
    double consumption;
public:
    Pkw(std::string& brand, double mileage, std::string& neededLicense, double consumption) : Vehicle(brand, mileage, neededLicense), consumption(consumption) {};
    double getConsumption() const
    {
        return consumption;
    }
    void printInfo() const override;
};


#endif