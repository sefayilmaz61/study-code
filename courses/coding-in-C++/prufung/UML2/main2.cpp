/**
 * file: main2.cpp
 * contains the main() function and methods of the Vehicle and Driver classes
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include "driver2.hpp"
#include "vehicle2.hpp"
#include "pkw2.hpp"
#include "electro2.hpp"

int Driver::nextId = 0;
int Vehicle::nextId = 0;

void Driver::removeLicense(std::string& removedLicense)
{
    auto it = std::find(licenses.begin(), licenses.end(), removedLicense);

    if (it != licenses.end())
    {
        licenses.erase(it);
    }
}

void Driver::lendVehicle(Vehicle* assignVehicle)
{
    if (this->assignedVehicle != nullptr)
    {
        std::cout << "Driver already has a vehicle assigned" << std::endl;
        return;
    }
    if(assignVehicle->isAvailable())
    {
        if(std::find(licenses.begin(), licenses.end(), assignVehicle->getNeededLicense()) != licenses.end())
        {
            this->assignedVehicle = assignVehicle;
            assignVehicle->lendVehicle();
            assignVehicle->assignedDriver();
        }
        else
        {
            std::cout << "Driver doesn't have the needed license" << std::endl;
        }
    }
    else
    {
        std::cout << "Vehicle isn't available" << std::endl;
    }
}

void Pkw::printInfo() const
{
    std::cout << std::setw(20) << "Type" << std::setw(20) << "PKW" << '\n';
    std::cout << std::setw(20) << "Brand" << std::setw(20) << this->getBrand() << '\n';
    std::cout << std::setw(20) << "Consumption per 100km" << std::setw(20) << this->getConsumption() << '\n';
    std::cout << std::setw(20) << "Availability" << std::setw(20) << std::boolalpha << this->isAvailable() << '\n';
    std::cout << std::setw(20) << "Needed License" << std::setw(20) << this->getNeededLicense() << '\n';
    std::cout << std::setw(20) << "Assigned Driver" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getName()) << '\n';
}

void Electro::printInfo() const
{
    std::cout << std::setw(20) << "Type" << std::setw(20) << "Electric" << '\n';
    std::cout << std::setw(20) << "Brand" << std::setw(20) << this->getBrand() << '\n';
    std::cout << std::setw(20) << "Capacity" << std::setw(20) << this->getCapacity() << '\n';
    std::cout << std::setw(20) << "Availability" << std::setw(20) << std::boolalpha << this->isAvailable() << '\n';
    std::cout << std::setw(20) << "Needed License" << std::setw(20) << this->getNeededLicense() << '\n';
    std::cout << std::setw(20) << "Assigned Driver" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getName()) << '\n';
}

int main()
{
    Pkw pkw1("Mercedes", 61, "SY", 67);
    Electro electro1("BMW", 66, "BB", 76);

    std::vector<std::string> driver1licenses;
    driver1licenses.push_back("BB");

    Driver driver1("eywa boss", driver1licenses);

    driver1.lendVehicle(&pkw1);

    pkw1.printInfo();
}