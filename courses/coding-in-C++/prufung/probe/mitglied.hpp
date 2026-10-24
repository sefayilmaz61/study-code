
#ifndef MITGLIED_HPP
#define MITGLIED_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "media.hpp"
#include "verwaltung.hpp"

class Medien;
class Verwaltung;

class Mitglied
{
private:
    static int nextid;
    int id;
    std::string name;
    std::vector<std::string> berechtigung;
public:

};

#endif