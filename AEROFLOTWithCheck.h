#ifndef AEROFLOTWITHCHECK_H
#define AEROFLOTWITHCHECK_H

#include "AEROFLOT.h"

class AEROFLOTWithCheck : public AEROFLOT {
public:
    // Конструктор с параметрами
    AEROFLOTWithCheck(const string& dest, const string& flight, const string& aircraft);

    // Переопределение метода display
    void display() const override;
};

#endif // AEROFLOTWITHCHECK_H
