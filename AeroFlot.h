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
    // Конструкторы и деструктор
    AEROFLOT(const string& dest, const string& flight, const string& aircraft);
    AEROFLOT();  // Конструктор по умолчанию
    AEROFLOT(const AEROFLOT& other);  // Конструктор копирования
    ~AEROFLOT();  // Деструктор

    // Методы для работы с данными
    string getDestination() const;
    string getFlightNumber() const;
    string getAircraftType() const;
    void setDestination(const string& dest);
    void setFlightNumber(const string& flight);
    void setAircraftType(const string& aircraft);

    // Метод проверки на пустоту
    bool isEmpty() const;

    // Метод для отображения рейса
    virtual void display() const;

    // Операторы
    friend ostream& operator<<(ostream& os, const AEROFLOT& flight);
    friend istream& operator>>(istream& is, AEROFLOT& flight);
};

#endif // AEROFLOT_H
