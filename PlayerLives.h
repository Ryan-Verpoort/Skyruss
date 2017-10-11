#ifndef PLAYERLIVES_H
#define PLAYERLIVES_H

#include "MovingObjects.h"
#include "Screen.h"

class PlayerLives : public MovingObjects
{
public:
    PlayerLives(Screen screen, int NumberOfLives);
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual void Move() override;
    virtual bool Status() override;
    virtual void Kill() override;
    virtual bool Respawns() override;
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _LivesPos;
    Screen _screen;
    bool _aliveStatus;
    float _CollisionRadius = 32;
};
#endif