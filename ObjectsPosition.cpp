#include "ObjectsPosition.h"

ObjectsPosition::ObjectsPosition()
{
}

void ObjectsPosition::SetInitialX(float InitialX)
{
    _InitialX = InitialX;
}

void ObjectsPosition::SetInitialY(float InitialY)
{
    _InitialY = InitialY;
}

void ObjectsPosition::SetCurrentX(float CurrentX)
{
    _CurrentX = CurrentX;
}

void ObjectsPosition::SetCurrentY(float CurrentY)
{
    _CurrentY = CurrentY;
}

void ObjectsPosition::setRadius(float Radius)
{
    _Radius = Radius;
}

void ObjectsPosition::setAngle(float Angle)
{
    _Angle = Angle;
}

float ObjectsPosition::GetCurrentX() const
{
    return _CurrentX;
}

float ObjectsPosition::GetCurrentY() const
{
    return _CurrentY;
}

float ObjectsPosition::GetInitialX() const
{
    return _InitialX;
}

float ObjectsPosition::GetInitialY() const
{
    return _InitialY;
}

float ObjectsPosition::GetRadius() const
{
    return _Radius;
}

float ObjectsPosition::GetAngle() const
{
    return _Angle;
}
