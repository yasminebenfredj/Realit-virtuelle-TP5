#include "rvorbit.h"

RVOrbit::RVOrbit(float h, float r, float d)
{
    this->h = h;
    this->r =r;
    this->d =d;

}

float RVOrbit::x(double t)
{
    float x = cos(t) *r +d;

    return x;
}

float RVOrbit::y(double t) {
    return  h;
}

float RVOrbit::z(double t)
{
    float z = sin(t) *r ;
    return z;
}

float RVOrbit::getR() const
{
    return r;
}

void RVOrbit::setR(float newR)
{
    r = newR;
}



float RVOrbit::getH() const
{
    return h;
}

void RVOrbit::setH(float newH)
{
    h = newH;
}
