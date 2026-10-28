/**
 * file: driver.hpp
 * @brief Defines the Driver class
 */

#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "vehicle.hpp"
#include "pkw.hpp"
#include "electro.hpp"

class Driver{
private:
    static int nextId;
    int id;
    std::string name;
    std::vector<std::string> licenses;
    Vehicle* assignedVehicle;
public:
    Driver(std::string& name, std::vector<std::string>& licenses) : id(++nextId), name(name), licenses(licenses), assignedVehicle(nullptr) {};
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
        return this->licenses;
    }
    void setName(std::string& name)
    {
        this->name = name;
    }
    void addLicense(const std::string& newLicense)
    {
        licenses.push_back(newLicense);
    }
    void removeLicense(const std::string& removedLicense);
    void lendVehicle(Vehicle* assignVehicle);
};
#endif 