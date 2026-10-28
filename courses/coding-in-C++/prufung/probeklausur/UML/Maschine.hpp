/** 
 * file: Maschine.hpp
 * @brief Defines the class Maschine
 */

 #ifndef MASCHINE_HPP
 #define MASCHINE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Maschinenfuehrer.hpp"

class Maschinenfuehrer;

class Maschine {
private:
    static int nextId;
    int id;
    std::string hersteller;
    bool status;
    std::string neededFuehrerschein;
    Maschinenfuehrer* assignedFuehrer;

public:
    Maschine(const std::string& hersteller, std::string& neededFuehrerschein) : id(++nextId), hersteller(hersteller), status(true), neededFuehrerschein(neededFuehrerschein), assignedFuehrer(nullptr) {};
    bool isAvailable() const
    {
        return status;
    }
    void lendMaschine()
    {
        status = false;
    }
    const std::string getHersteller() const
    {
        return hersteller;
    }
    const int getId() const
    {
        return id;
    }

};



 #endif