/**
 * file: electro2.hpp
 * @brief Defines the Electro class 
 */

#ifndef ELECTRO2_HPP
#define ELECTRO_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "vehicle2.hpp"
#include "driver2.hpp"

class Electro : public Vehicle
{
private: 
    double capacity;
public: 
    Electro(std::string& brand, double mileage, std::string& neededLicense, double capacity) : Vehicle(brand, mileage, neededLicense), capacity(capacity){};
    double getCapacity() const
    {
        return capacity;
    }
    void printInfo() const override;
};

#endif