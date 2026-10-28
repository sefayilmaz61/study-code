/**
 * file: driver2.hpp
 * @brief Defines the Driver class
 */

#ifndef DRIVER2_HPP
#define DRIVER2_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "vehicle2.hpp"
#include "pkw2.hpp"
#include "electro2.hpp"

class Vehicle;

class Driver
{
private:
    static int nextId;
    int id;
    std::string name;
    std::vector<std::string> licenses;
    Vehicle* assignedVehicle;
public:
    Driver(std::string& name, std::vector<std::string> licenses) : id(++nextId), name(name), licenses(licenses), assignedVehicle(nullptr){};
    int getId() const
    {
        return id;
    }
    const std::string& getName() const
    {
        return name;
    }
    const std::vector<std::string>& getLicenses() const
    {
        return licenses;
    }
    Vehicle* getAssignedVehicle() const
    {
        return assignedVehicle;
    }
    void setName(std::string& name)
    {
        this->name = name;
    }
    void addLicense(std::string& newLicense)
    {
        licenses.push_back(newLicense);
    }
    void removeLicense(std::string& removedLicense);
    void lendVehicle(Vehicle* assignVehicle);
};

#endif