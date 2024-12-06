#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <string>
#include <iostream>
#include <stdexcept>

class AEROFLOT {
private:
    std::string destination;
    std::string flightNumber;
    std::string aircraftType;

public:

    AEROFLOT();

    AEROFLOT(const std::string &dest, const std::string &num, const std::string &type);

    AEROFLOT(const AEROFLOT &other);

    virtual ~AEROFLOT();

    std::string getDestination() const;
    void setDestination(const std::string &dest);

    std::string getFlightNumber() const;
    void setFlightNumber(const std::string &num);

    std::string getAircraftType() const;
    void setAircraftType(const std::string &type);

    AEROFLOT& operator=(const AEROFLOT &other);

    friend std::ostream& operator<<(std::ostream &os, const AEROFLOT &flight);
    friend std::istream& operator>>(std::istream &is, AEROFLOT &flight);
};

#endif
