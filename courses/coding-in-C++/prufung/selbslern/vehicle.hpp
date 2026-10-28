/**
 * file:vehicle.hpp
 * @brief Defines the Vehicle class
 */

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include <vector>
#include "driver.hpp"

class Driver;

class Vehicle
{
private:
    static int nextId;
    int id;
    std::string brand;
    double mileage;
    std::string neededLicense;
    bool availability;
    Driver* assignedDriver;
public:
    Vehicle(std::string& brand, double mileage, std::string& neededLicense) : id(++nextId), brand(brand), mileage(mileage), neededLicense(neededLicense), availability(true), assignedDriver(nullptr){};
    

    virtual void printInfo() const = 0;
    virtual ~Vehicle() = default;
}   

#endif