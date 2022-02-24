#include "rvbounce.h"

RVBounce::RVBounce(double hMax, double tMax)
{
    this->hMax = hMax;
    this->tMax = tMax;
    a = - hMax /(tMax*tMax);
    b = - a * 2 * tMax;
}

float RVBounce::x(double t)
{
    return 0.0f;
}

float RVBounce::y(double t) {
    t = std::fmod(t,2*tMax);
    float y = a*(t*t) + b*t;
    //printf("a = %f \nb = %f\nt = %f \ny = %f\n",a, b, t, y);
    return y;
}

float RVBounce::z(double t)
{
    return 0.0f;
}


