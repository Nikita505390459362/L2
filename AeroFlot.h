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

    AEROFLOT(const string& dest, const string& flight, const string& aircraft);
    AEROFLOT();
    AEROFLOT(const AEROFLOT& other);
    ~AEROFLOT();

    string getDestination() const;
    string getFlightNumber() const;
    string getAircraftType() const;
    void setDestination(const string& dest);
    void setFlightNumber(const string& flight);
    void setAircraftType(const string& aircraft);

    bool isEmpty() const;

    virtual void display() const;

    friend ostream& operator<<(ostream& os, const AEROFLOT& flight);
    friend istream& operator>>(istream& is, AEROFLOT& flight);
};

#endif // AEROFLOT_H
