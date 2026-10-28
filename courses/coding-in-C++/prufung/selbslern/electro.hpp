/**
 * file: electro.hpp
 * @brief Defines the electro class
 */

#ifndef ELECTRO_HPP
#define ELECTRO_HPP

#include <string>
#include <iostream>
#include "vehicle.hpp"
#include "driver.hpp"

class Electro : public Vehicle{
private:
    double capacity;
public:
    Electro(std::string& brand, double mileage, std::string& neededLicense, double capacity) : Vehicle(brand, mileage, neededLicense), capacity(capacity) {};
    double getCapacity() const 
    {
        return capacity;
    }
    void printInfo() const override;
};

#endif