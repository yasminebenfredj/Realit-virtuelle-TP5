#ifndef RVORBIT_H
#define RVORBIT_H

#include "rvcurve.h"

class RVOrbit : public RVCurve
{
public:
    RVOrbit(float h = 10.0f, float r = 10.0f, float d = 10.0f);


    float getH() const;
    void setH(float newH);

    float getR() const;
    void setR(float newR);

protected:

    float x(double t) override;              //!< Fonction qui donne l'abscisse en fonction du temps
    float y(double t) override;      //!< Fonction qui donne l'ordonnée en fonction du temps
    float z(double t) override;

    float a;
    float b;
    float c = 0;

    float h;
    float r;
    float d;
};

#endif // RVORBIT_H
