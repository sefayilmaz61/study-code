
#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Driver;

class Vehicle 
{
private:
    static int nextId;
    int id;
    std::string brand;
    double mileage;
    std::string neededLicense;
    bool availability; // true when available
    Driver *assignedDriver;
public:
    Vehicle (const std::string& brand, double mileage, const std::string& neededLicense) : id(++nextId), brand(brand), mileage(mileage), neededLicense(neededLicense), availability(true), assignedDriver(nullptr) {};
    int getId() const
    {
        return id;
    }
    void setId(int id)
    {
        this->id = id;
    }

    virtual void printInfo() const = 0;
    virtual ~Vehicle() = default;

};

class Pkw : public Vehicle  
{

};

class Electro: public Vehicle
{

};
#endif