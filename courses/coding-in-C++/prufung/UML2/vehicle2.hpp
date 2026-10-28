/**
 * file: vehicle2.hpp
 * @brief Defines the Vehicle class 
 */

#ifndef VEHICLE2_HPP
#define VEHICLE2_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "driver2.hpp"


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
    Vehicle(std::string& brand, double mileage, std::string neededLicense) : id(++nextId), brand(brand), mileage(mileage), neededLicense(neededLicense), availability(true), assignedDriver(nullptr) {};
    bool isAvailable() const
    {
        return availability;
    }
    void lendVehicle()
    {
        availability = false;
    }
    const std::string& getBrand() const
    {
        return brand;
    }
    double getMileage() const
    {
        return mileage;
    }
    const std::string getNeededLicense() const
    {
        return neededLicense;
    }
    Driver* getAssignedDriver() const
    {
        return assignedDriver;
    }
    void setDriver(Driver* assignedDriver)
    {
        this->assignedDriver = assignedDriver;
    }
    void setBrand(std::string& brand)
    {
        this->brand = brand;
    }
    virtual void printInfo() const = 0;
    virtual ~Vehicle() = default;
};


#endif