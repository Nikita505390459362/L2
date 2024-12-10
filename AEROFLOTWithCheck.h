#ifndef AEROFLOTWITHCHECK_H
#define AEROFLOTWITHCHECK_H

#include "AEROFLOT.h"

class AEROFLOTWithCheck : public AEROFLOT {
public:
    AEROFLOTWithCheck(string dest, string flight, string aircraft);


    void display() const override;
};

#endif // AEROFLOTWITHCHECK_H
