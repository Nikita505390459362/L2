#include "AEROFLOTWithCheck.h"
#include <stdexcept>
#include <iostream>

using namespace std;


AEROFLOTWithCheck::AEROFLOTWithCheck(const string& dest, const string& flight, const string& aircraft)
        : AEROFLOT(dest, flight, aircraft) {}

void AEROFLOTWithCheck::display() const {
    if (isEmpty()) {
        throw invalid_argument("Одно из полей пустое!");
    }
    AEROFLOT::display();
}
