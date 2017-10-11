#ifndef SHOOTINGOBJECTS_H
#define SHOOTINGOBJECTS_H

#include "MovingObjects.h"
#include <cmath>
#include <memory>
using std::shared_ptr;

const float PI = M_PI;
const float ANGLE_OFFSET = M_PI_2;

class ShootingObjects : public MovingObjects
{
public:
    virtual ObjectsPosition GetPosition() = 0;
    virtual Objects GetObject() = 0;
    virtual void Move() = 0;
    virtual bool Status() = 0;
    virtual shared_ptr<MovingObjects> Shoot() = 0;
    virtual bool Respawns() = 0;
    virtual void Kill() = 0;
    virtual float GetCollisionRadius() = 0;
};

#endif