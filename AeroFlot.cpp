#include "AEROFLOT.h"


AEROFLOT::AEROFLOT(string dest, string flight, string aircraft)
        : destination(dest), flightNumber(flight), aircraftType(aircraft) {
    cout << "Конструктор с параметрами для рейса " << flightNumber << " вызван.\n";
}

AEROFLOT::AEROFLOT() : destination(""), flightNumber(""), aircraftType("") {
    cout << "Конструктор по умолчанию вызван.\n";
}

AEROFLOT::AEROFLOT(const AEROFLOT& other)
        : destination(other.destination), flightNumber(other.flightNumber), aircraftType(other.aircraftType) {
    cout << "Конструктор копирования для рейса " << other.flightNumber << " вызван.\n";
}

AEROFLOT::~AEROFLOT() {
    cout << "Деструктор для рейса " << flightNumber << " вызван.\n";
}

string AEROFLOT::getDestination() const { return destination; }
string AEROFLOT::getFlightNumber() const { return flightNumber; }
string AEROFLOT::getAircraftType() const { return aircraftType; }

void AEROFLOT::setDestination(const string& dest) { destination = dest; }
void AEROFLOT::setFlightNumber(const string& flight) { flightNumber = flight; }
void AEROFLOT::setAircraftType(const string& aircraft) { aircraftType = aircraft; }

void AEROFLOT::display() const {
    cout << "Рейс " << flightNumber << ": Пункт назначения - " << destination
         << ", Тип самолета - " << aircraftType << endl;
}

ostream& operator<<(ostream& os, const AEROFLOT& flight) {
    os << "Пункт назначения: " << flight.destination << ", Номер рейса: "
       << flight.flightNumber << ", Тип самолета: " << flight.aircraftType;
    return os;
}

istream& operator>>(istream& is, AEROFLOT& flight) {
    cout << "Введите пункт назначения: ";
    getline(is, flight.destination);
    cout << "Введите номер рейса: ";
    getline(is, flight.flightNumber);
    cout << "Введите тип самолета: ";
    getline(is, flight.aircraftType);
    return is;
}
