#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "MovingObjects.h"
#include "ShootingObjects.h"
#include "Screen.h"
#include "Player.h"

#include <cmath>
#include <memory>
using std::shared_ptr;

class EnemyBullet : public MovingObjects
{
public:
    EnemyBullet(ObjectsPosition enemyPos, Screen screen);
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual void Move() override;
    virtual bool Status() override;
    virtual bool Respawns() override;
    virtual void Kill() override;
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _enemyBulletPos;
    bool _IsAlive;
    Screen _screen;
    float _DistToPlayer;
    float _EnemyBulletSpeed = 0.00001;
    float _CollisionRadius = 32;
};

#endif
