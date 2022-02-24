#ifndef RVSURFACE_H
#define RVSURFACE_H


#include <QtMath>
#include <QtDebug>
#include "rvbody.h"


class RVSurface : public RVBody
{
public:
    RVSurface();
    void draw() override;
    void initializeBuffer() override;

    virtual QVector3D pos(double s, double t) {
        return QVector3D(x(s,t), y(s,t), z(s,t));
    }

    QVector3D normal(double s, double t);

protected:
    virtual float x(double s, double t) = 0;
    virtual float y(double s, double t) = 0;
    virtual float z(double s, double t) = 0;
    QVector3D gradS(double s, double t);
    QVector3D gradT(double s, double t);

    double minT, maxT;       //!< définit l'intervalle en t
    int numSegT;              //!< nb de subdivisions de l'intervalle en t
    double minS, maxS;       //!< définit l'intervalle en s
    int numSegS;              //!< nb de subdivisions de l'intervalle en s
    float time = 0;

    double ds = 0.1;
    double dt = 0.1;

};
#endif // RVSURFACE_H
