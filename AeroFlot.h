#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class AEROFLOT {
protected:
    string destination;
    string flightNumber;
    string aircraftType;

public:

    AEROFLOT(string dest, string flight, string aircraft);

    AEROFLOT();

    AEROFLOT(const AEROFLOT& other);

    virtual ~AEROFLOT();

    string getDestination() const;
    string getFlightNumber() const;
    string getAircraftType() const;

    void setDestination(const string& dest);
    void setFlightNumber(const string& flight);
    void setAircraftType(const string& aircraft);

    virtual void display() const;

    friend ostream& operator<<(ostream& os, const AEROFLOT& flight);

    friend istream& operator>>(istream& is, AEROFLOT& flight);
};

#endif // AEROFLOT_H
