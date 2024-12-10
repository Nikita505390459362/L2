#include "AEROFLOTWithCheck.h"
#include <stdexcept>

AEROFLOTWithCheck::AEROFLOTWithCheck(string dest, string flight, string aircraft)
        : AEROFLOT(dest, flight, aircraft) {}


void AEROFLOTWithCheck::display() const {
    if (destination.empty() || flightNumber.empty() || aircraftType.empty()) {
        throw invalid_argument("Одно из полей пустое!");
    }
    AEROFLOT::display();
}
