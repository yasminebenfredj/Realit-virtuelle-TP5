#ifndef RVSTEREOCAMERA_H
#define RVSTEREOCAMERA_H
#define RV_CAMERA_MONO  0
#define RV_CAMERA_LEFT  1
#define RV_CAMERA_RIGHT 2

#include <math.h>

#include "rvcamera.h"

class RVStereoCamera : public RVCamera
{
public:
    RVStereoCamera();

    float getEyeDistance() const;
    void setEyeDistance(float newEyeDistance);

    float getFocalDistance() const;
    void setFocalDistance(float newFocalDistance);

    int getCameraType() const;
    void setCameraType(int newCameraType);

    QMatrix4x4 viewMatrix() override;
    QMatrix4x4 projectionMatrix() override;

private :
    float eyeDistance ;
    float focalDistance;
    int cameraType ;

protected :
    QMatrix4x4 leftViewMatrix();
    QMatrix4x4 leftProjectionMatrix();
    QMatrix4x4 rightViewMatrix();
    QMatrix4x4 rightProjectionMatrix();

};

#endif // RVSTEREOCAMERA_H
