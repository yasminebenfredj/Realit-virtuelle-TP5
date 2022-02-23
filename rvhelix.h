#ifndef RVHELIX_H
#define RVHELIX_H

#include "rvcurve.h"

class RVHelix : public RVCurve
{
public:
    RVHelix(double radius = 1.0, double pitch = 0.2);

    double getRadius() const;
    void setRadius(double radius);

    double getFrequency() const;
    void setFrequency(double frequency);

    double getPitch() const;
    void setPitch(double pitch);

    double getNumWindings() const;
    void setNumWindings(double numWindings);

protected:
    float x(double t) override;
    float y(double t) override;
    float z(double t) override;

    double radius;         //!< rayon de l'hélice
    double frequency;      //!< fréquence de rotation (nb tour/s)
    double pitch;          //!< pas de l'hélice (de combien elle avance à chaque tour)
    double numWindings;    //!< nombre d'enroulements
};

#endif // RVHELIX_H
