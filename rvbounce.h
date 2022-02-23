#ifndef RVBOUNCE_H
#define RVBOUNCE_H

#include "rvcurve.h"

class RVBounce : public RVCurve
{
public:
    RVBounce(double hMax = 10.0, double tMax = 10.0);


protected:

    float x(double t) override;              //!< Fonction qui donne l'abscisse en fonction du temps
    float y(double t) override;      //!< Fonction qui donne l'ordonnée en fonction du temps
    float z(double t) override;

    float a;
    float b;
    float c = 0;

    double hMax;
    double tMax;
};

#endif // RVBOUNCE_H
