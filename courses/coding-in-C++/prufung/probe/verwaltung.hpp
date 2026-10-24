
#ifndef VERWALTUNG_HPP
#define VERWALTUNG_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "mitglied.hpp"
#include "media.hpp"

class Mitglied;
class Medien;

class Verwaltung
{
private:
    std::vector<unique_ptr> mitglieder;
    std::vector<unique_ptr> medien;
    std::vector<std::string> elements;
public:

};

#endif