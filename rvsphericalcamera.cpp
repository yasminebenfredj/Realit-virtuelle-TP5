#include "rvsphericalcamera.h"
#include <cmath>

RVSphericalCamera::RVSphericalCamera() :  RVStereoCamera()
{
    phi = M_PI/4;
    theta = 0;
    rho = 20;
    updatePosition();
}

float RVSphericalCamera::getPhi() const
{
    return phi;
}

void RVSphericalCamera::setPhi(float newPhi)
{
    phi = qMin(M_PI_2, qMax(newPhi, -M_PI_2));
    this->updatePosition();
}

float RVSphericalCamera::getTheta() const
{
    return theta;
}

void RVSphericalCamera::setTheta(float newTheta)
{
    theta = newTheta;
    this->updatePosition();
}

float RVSphericalCamera::getRho() const
{
    return rho;
}

void RVSphericalCamera::setRho(float newRho)
{
    rho = qMax(newRho, 0.1);
    this->updatePosition();
}

void RVSphericalCamera::update()
{
    this->updatePosition();
}

void RVSphericalCamera::updatePosition()
{
    float x = this->target.x() + rho * qCos(phi) * qCos(theta);
    float y = this->target.y() + rho * qSin(phi);
    float z = this->target.z() + rho * qCos(phi) * qSin(theta) ;
    this->position = QVector3D(x, y, z);
}
