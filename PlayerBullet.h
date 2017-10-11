#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "Screen.h"
#include "MovingObjects.h"
#include "ShootingObjects.h"

class PlayerBullet : public MovingObjects
{
public:
    PlayerBullet(ObjectsPosition playerPos, Screen screen);
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual void Move() override;
    virtual bool Status() override;
    virtual bool Respawns() override;
    virtual void Kill() override;
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _playerBulletPos;
    bool _aliveStatus;
    Screen _screen;
    bool _reSpawn;
    int newXPos;
    int newYPos;

    float _CollisionRadius = 30;
};

#endif