

#ifndef MEDIEN_HPP
#define MEDIEN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "mitglied.hpp"
#include "verwaltung.hpp"

class Mitglied;
class Verwaltung;

class Media
{
private:
    static int nextid;
    int id;
    std::string title;
    bool availability;
    bool neededBerechtigung;
    Mitglied* assignedMitglied;
public:
    Media(const std::string& title, bool neededBerechtigung) : id(++nextid), title(title), availability(true), neededBerechtigung(neededBerechtigung), assignedMitglied(nullptr) {};

    // Getters
    int getId() const
    {
        return id;
    }
    std::string getTitle() const        
    {
        return title;
    }
    bool getAvailability() const
    {
        return availability;
    }
    bool getNeededBerechtigung() const
    {
        return neededBerechtigung;
    }
    Mitglied* getAssignedMitglied() const
    {
        return assignedMitglied;
    }

    // Setters
    void setTitle(std::string& title)
    { 
        this->title = title; 
    }
    void setAvailability(bool availability)
    {
        this->availability = availability;
    }
    void setNeededBerechtigung(bool neededBerechtigung)
    {
        this->neededBerechtigung = neededBerechtigung;
    }
    void setAssignedMitglied (Mitglied* mitglied)
    {
        this->assignedMitglied = mitglied;
    }
    void lendMedium() 
    {
	    availability = false;
    }
    bool isAvailable() const
    {
        return availability;
    }
    virtual void printInfo() const = 0;
	virtual ~Media() = default;
        

};

class EBook : public Media
{
private:
    double dateigrosse;
public:
    EBook(const std::string& title, bool neededBerechtigung, double dateigrosse) : Media(title, neededBerechtigung), dateigrosse(dateigrosse) {};
    void printInfo() const override;
    double getDateigrosse () const
    {
        return dateigrosse;
    }
    void setDateigrosse(double dateigrosse)
    {
        this->dateigrosse = dateigrosse;
    }
};

class Horbuch : public Media
{
private:
    double laufzeit;
public:
    Horbuch(const std::string& title, bool neededBerechtigung, double laufzeit) : Media(title, neededBerechtigung), laufzeit(laufzeit) {};
    void printInfo() const override;
    double getLaufzeit() const
    {
        return laufzeit;
    }
    void setLaufzeit(double laufzeit)
    {
        this->laufzeit = laufzeit;
    }
};

#endif