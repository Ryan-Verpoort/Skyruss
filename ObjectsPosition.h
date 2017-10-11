#ifndef OBJECTSPOSITION_H
#define OBJECTSPOSITION_H

class ObjectsPosition
{
public:
    ObjectsPosition();

    void SetInitialX(float InitialX);
    void SetInitialY(float InitialY);
    void SetCurrentX(float CurrentX);
    void SetCurrentY(float CurrentY);
    void setRadius(float Radius);
    void setAngle(float Angle);

    float GetInitialX() const;
    float GetInitialY() const;
    float GetCurrentX() const;
    float GetCurrentY() const;
    float GetRadius() const;
    float GetAngle() const;

private:
    float _InitialX;
    float _InitialY;
    float _CurrentX;
    float _CurrentY;
    float _Radius;
    float _Angle;
};

#endif