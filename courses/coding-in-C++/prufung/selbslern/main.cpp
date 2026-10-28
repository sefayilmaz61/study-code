/**
 * file: main.cpp
 * @brief contains main() function and method defintions for the classes Vehicle and Driver
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include "driver.hpp"
#include "vehicle.hpp"
#include "pkw.hpp"
#include "electro.hpp"

int Driver::nextId = 0;
int Vehicle::nextId = 0;

void Driver::removeLicense(const std::string& removedLicense)
{
    auto it = std::find(licenses.begin(), licenses.end(), removedLicense);
    
    if (it != licenses.end())
    {
        licenses.erase(it);
    }
}

void Driver::lendVehicle(Vehicle* assignVehicle)
{
    if(this->assignedVehicle != nullptr)
    {
        std::cout << "Driver already has a vehicle assigned" <<std::endl;
        return;
    }
    if (assignVehicle->isAvailable())
    {
        if(std::find(licenses.begin(), licenses.end(), assignVehicle->getNeededLicense()) != licenses.end())
        {
            this->assignedVehicle = assignVehicle;
            assignVehicle->lendVehicle();
            assignVehicle->assignDriver(this);
        }
        else
        {
            std::cout << "Driver doesn't have needed license for this vehicle" << std::endl;
        }
    }
    else
    {
        std::cout << "Vehicle ist available" << std::endl;
    }
        
}

void Pkw::printInfo() const
{
    std::cout << std::setw(20) << "Type" << std::setw(20) << "PKW" << '\n';
    std::cout << std::setw(20) << "Brand" << std::setw(20) << this->getBrand() << '\n';
    std::cout << std::setw(20) << "Mileage" << std::setw(20) << this->getMileage() << '\n';
    std::cout << std::setw(20) << "Consumption per 100km" << std::setw(20) << this->getConsumption() << '\n';
    std::cout << std::setw(20) << "Availability" << std::setw(20) << std::boolalpha << this->isAvailable() << '\n';
    std::cout << std::setw(20) << "Needed License" << std::setw(20) << this->getNeededLicense() << '\n';
    std::cout << std::setw(20) << "Assigned Driver" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getName()) << '\n';
}

void Electro::printInfo() const
{
    std::cout << std::setw(20) << "Type" << std::setw(20) << "Electric" << '\n';
    std::cout << std::setw(20) << "Brand" << std::setw(20) << this->getBrand() << '\n';
    std::cout << std::setw(20) << "Mileage" << std::setw(20) << this->getMileage() << '\n';
    std::cout << std::setw(20) << "Capacity" << std::setw(20) << this->getCapacity() << '\n';
    std::cout << std::setw(20) << "Availability" << std::setw(20) << std::boolalpha << this->isAvailable() << '\n';
    std::cout << std::setw(20) << "Needed License" << std::setw(20) << this->getNeededLicense() << '\n';
    std::cout << std::setw(20) << "Assigned Driver" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getName()) << '\n';
}

int main()
{
    Pkw pkw1("Mercedes", 61, "B", 10.9);
    Electro electro1("Mercedes", 167, "B", 70);

    std::vector<std::string> driver1licenses;
    driver1licenses.push_back("B");
    driver1licenses.push_back("C1");

    Driver driver1("Sefa Yilmaz", driver1licenses);

    driver1.lendVehicle(&pkw1);

    pkw1.printInfo();
}