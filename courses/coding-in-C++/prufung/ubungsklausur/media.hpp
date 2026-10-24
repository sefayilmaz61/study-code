
#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "library.hpp"

class Library;

class Media {
private:
    int id;
    std::string title;
    bool isBorrwed;
public:

};

class Book : public Media {
private:
    std::string author;
    int page_count;
};

class Movie : public Media {
private:
    std::string director;
    int duration_minutes;
};

#endif