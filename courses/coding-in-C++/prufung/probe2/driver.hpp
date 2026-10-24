/*
*file: driver.hpp
* @brief Defines the class Driver
*/


#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <string>
#include <vector>
 

class Vehicle;

class Driver
{
private:
    static int nextId;
    int id;
    std::string name;
    std::vector<std::string> licenses;
public:
    Driver(const std::string& name, std::vector<std::string> licenses&) : id(++nextId), name(name) {};
    int getId () const
    {
        return id;
    }
    std::string getName()
    {
        return name;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setName(std::string& name)
    {
        this->name = name;
    }
};
#endif