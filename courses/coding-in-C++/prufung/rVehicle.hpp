
#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Driver.hpp"

class Driver;

class Vehicle 
{
private:
    static int nextid;
    int id;
    std::string brand;
    double mileage;
    std::string neededLicense;
    bool availability;
    Driver* assignedDriver;
public:
    getBrand
};

class PKW : public Vehicle
{
private:
    double consumption;
public:
    void printInfo()
};

class Elecric : public Vehicle 
{
private:
    double capacity;
public:
    void printInfo()
};

#endif