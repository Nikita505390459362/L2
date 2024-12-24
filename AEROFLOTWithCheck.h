#ifndef AEROFLOTWITHCHECK_H
#define AEROFLOTWITHCHECK_H

#include "AEROFLOT.h"

class AEROFLOTWithCheck : public AEROFLOT {
public:
    AEROFLOTWithCheck(const string& dest, const string& flight, const string& aircraft);


    void display() const override;
};

#endif // AEROFLOTWITHCHECK_H
