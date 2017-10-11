#ifndef MOVINGOBJECTS_H
#define MOVINGOBJECTS_H

#include "Objects.h"
#include "ObjectsPosition.h"

class MovingObjects
{
public:
    virtual ObjectsPosition GetPosition() = 0;
    virtual Objects GetObject() = 0;
    virtual void Move() = 0;
    virtual bool Status() = 0;
    virtual void Kill() = 0;
    virtual bool Respawns() = 0;
    virtual float GetCollisionRadius() = 0;
};

#endif