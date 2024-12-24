#include "AEROFLOTWithCheck.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Конструктор с параметрами
AEROFLOTWithCheck::AEROFLOTWithCheck(const string& dest, const string& flight, const string& aircraft)
        : AEROFLOT(dest, flight, aircraft) {}

// Переопределение метода display с проверкой на пустые поля
void AEROFLOTWithCheck::display() const {
    // Проверка на пустые поля
    if (isEmpty()) {
        throw invalid_argument("Одно из полей пустое!");
    }
    // Вызов метода display из базового класса
    AEROFLOT::display();
}
