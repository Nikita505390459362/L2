#include "AEROFLOT.h"

AEROFLOT::AEROFLOT(const string& dest, const string& flight, const string& aircraft)
        : destination(dest), flightNumber(flight), aircraftType(aircraft) {
    // Удалено уведомление о вызове конструктора
}

AEROFLOT::AEROFLOT() : destination(""), flightNumber(""), aircraftType("") {
    // Удалено уведомление о вызове конструктора
}

AEROFLOT::AEROFLOT(const AEROFLOT& other)
        : destination(other.destination), flightNumber(other.flightNumber), aircraftType(other.aircraftType) {
    // Удалено уведомление о вызове конструктора копирования
}

AEROFLOT::~AEROFLOT() noexcept {
    // Удалено уведомление о вызове деструктора
}

string AEROFLOT::getDestination() const { return destination; }
string AEROFLOT::getFlightNumber() const { return flightNumber; }
string AEROFLOT::getAircraftType() const { return aircraftType; }

void AEROFLOT::setDestination(const string& dest) { destination = dest; }
void AEROFLOT::setFlightNumber(const string& flight) { flightNumber = flight; }
void AEROFLOT::setAircraftType(const string& aircraft) { aircraftType = aircraft; }

bool AEROFLOT::isEmpty() const {
    return destination.empty() || flightNumber.empty() || aircraftType.empty();
}

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
    if (!getline(is, flight.destination)) return is;
    cout << "Введите номер рейса: ";
    if (!getline(is, flight.flightNumber)) return is;
    cout << "Введите тип самолета: ";
    if (!getline(is, flight.aircraftType)) return is;
    return is;
}
