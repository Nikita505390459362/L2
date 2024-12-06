#include "AEROFLOT.h"


AEROFLOT::AEROFLOT() : destination("Unknown"), flightNumber("0000"), aircraftType("Unknown") {
    std::cout << "Default constructor called for AEROFLOT" << std::endl;
}

AEROFLOT::AEROFLOT(const std::string &dest, const std::string &num, const std::string &type)
        : destination(dest), flightNumber(num), aircraftType(type) {
    std::cout << "Constructor with parameters called for AEROFLOT" << std::endl;
}

AEROFLOT::AEROFLOT(const AEROFLOT &other)
        : destination(other.destination), flightNumber(other.flightNumber), aircraftType(other.aircraftType) {
    std::cout << "Copy constructor called for AEROFLOT" << std::endl;
}

AEROFLOT::~AEROFLOT() {
    std::cout << "Destructor called for AEROFLOT" << std::endl;
}

std::string AEROFLOT::getDestination() const {
    return destination;
}

void AEROFLOT::setDestination(const std::string &dest) {
    destination = dest;
}

std::string AEROFLOT::getFlightNumber() const {
    return flightNumber;
}

void AEROFLOT::setFlightNumber(const std::string &num) {
    flightNumber = num;
}

std::string AEROFLOT::getAircraftType() const {
    return aircraftType;
}

void AEROFLOT::setAircraftType(const std::string &type) {
    aircraftType = type;
}

AEROFLOT& AEROFLOT::operator=(const AEROFLOT &other) {
    if (this == &other) {
        return *this;
    }

    destination = other.destination;
    flightNumber = other.flightNumber;
    aircraftType = other.aircraftType;

    std::cout << "Assignment operator called for AEROFLOT" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const AEROFLOT &flight) {
    os << "Destination: " << flight.getDestination()
       << ", Flight Number: " << flight.getFlightNumber()
       << ", Aircraft Type: " << flight.getAircraftType();
    return os;
}

std::istream& operator>>(std::istream &is, AEROFLOT &flight) {
    std::string temp;
    std::cout << "Enter destination: ";
    is >> temp;
    flight.setDestination(temp);

    std::cout << "Enter flight number: ";
    is >> temp;
    flight.setFlightNumber(temp);

    std::cout << "Enter aircraft type: ";
    is >> temp;
    flight.setAircraftType(temp);

    return is;
}
