#include "rvstereocamera.h"

RVStereoCamera::RVStereoCamera() : RVCamera()
{
    this->setCameraType(RV_CAMERA_MONO);
    this->setEyeDistance(2);
    this->setFocalDistance(60);
}

float RVStereoCamera::getEyeDistance() const
{
    return eyeDistance;
}

void RVStereoCamera::setEyeDistance(float newEyeDistance)
{
    eyeDistance = newEyeDistance;
}

float RVStereoCamera::getFocalDistance() const
{
    return focalDistance;
}

void RVStereoCamera::setFocalDistance(float newFocalDistance)
{
    focalDistance = newFocalDistance;
}

int RVStereoCamera::getCameraType() const
{
    return cameraType;
}

void RVStereoCamera::setCameraType(int newCameraType)
{
    cameraType = newCameraType;
}

QMatrix4x4 RVStereoCamera::viewMatrix()
{
    switch (cameraType){
    case RV_CAMERA_MONO :
        return RVCamera::viewMatrix();
        break;
    case RV_CAMERA_LEFT :
        return RVStereoCamera::leftViewMatrix();
        break;
    case RV_CAMERA_RIGHT :
        return RVStereoCamera::rightViewMatrix();
        break;
    default:
        return RVCamera::viewMatrix();
    }

}

QMatrix4x4 RVStereoCamera::projectionMatrix()
{
    switch (cameraType){
    case RV_CAMERA_MONO :
        return RVCamera::projectionMatrix();
        break;
    case RV_CAMERA_LEFT :
        return RVStereoCamera::leftProjectionMatrix();
        break;
    case RV_CAMERA_RIGHT :
        return RVStereoCamera::rightProjectionMatrix();
        break;
    default:
        return RVCamera::projectionMatrix();
    }
}

QMatrix4x4 RVStereoCamera::leftViewMatrix()
{
    QMatrix4x4 view;

    QVector3D v = QVector3D(sqrt(pow(target.x()-position.x(),2)),
                           sqrt(pow(target.y()-position.y(),2)),
                           sqrt(pow(target.z()-position.z(),2))) * up;

    float norme = sqrt(pow(v.x(),2)+pow(v.y(),2)+pow(v.z(),2));
    QVector3D pOG = position - (eyeDistance/2)*(v/norme);//v.length());
    QVector3D tOG = target - (eyeDistance/2)*(v/norme);//v.length());
    view.lookAt(pOG, tOG, up);
    return view;
}

QMatrix4x4 RVStereoCamera::rightViewMatrix()
{
    QMatrix4x4 view;
    QVector3D v =  QVector3D(sqrt(pow(target.x()-position.x(),2)),
                             sqrt(pow(target.y()-position.y(),2)),
                             sqrt(pow(target.z()-position.z(),2))) * up ;

    float norme = sqrt(pow(v.x(),2)+pow(v.y(),2)+pow(v.z(),2));
    QVector3D pOG = position - (eyeDistance/2)*(v/norme);//v.length());
    QVector3D tOG = target -(eyeDistance/2)*(v/norme);//v.length());
    view.lookAt(pOG, tOG, up);
    return view;
}


QMatrix4x4 RVStereoCamera::leftProjectionMatrix()
{
    QMatrix4x4 proj;
    if (!orthogonal) {
        float top = zMin * tan((fov*(M_PI/180))/2);
        float bottom = - top;

        float a = focalDistance * aspect * tan((fov*(M_PI/180))/2);
        float b = a-(eyeDistance/2);
        float c = (2*a)-b;


        float left = -(b/focalDistance)*zMin;
        float right = (c/focalDistance)*zMin;
        proj.frustum(left, right, bottom, top, zMin, zMax);
    }else
    {
        float bottom = -fov/2;
        float top = fov/2;
        float left = bottom * aspect;
        float right = top * aspect;
        proj.ortho(left, right, bottom, top, zMin, zMax);
    }
    return proj;
}


QMatrix4x4 RVStereoCamera::rightProjectionMatrix()
{
    QMatrix4x4 proj;
    if (!orthogonal) {
        float top = zMin * tan((fov*(M_PI/180))/2);
        float bottom = - top;

        float a = focalDistance * aspect * tan((fov*(M_PI/180))/2);
        float b = a-(eyeDistance/2);
        float c = (2*a)-b;


        float left = -(c/focalDistance)*zMin;
        float right = (b/focalDistance)*zMin;
        proj.frustum(left, right, bottom, top, zMin, zMax);
    }else
    {
        float bottom = -fov/2;
        float top = fov/2;
        float left = bottom * aspect;
        float right = top * aspect;
        proj.ortho(left, right, bottom, top, zMin, zMax);
    }
    return proj;
}
