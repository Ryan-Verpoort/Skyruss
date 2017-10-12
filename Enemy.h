#ifndef ENEMY_H
#define ENEMY_H

#include "ShootingObjects.h"
#include "Screen.h"
#include "EnemyBullet.h"

class Enemy : public ShootingObjects
{
public:
    Enemy(Screen screen);
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual void Move() override;
    virtual bool Status() override;
    virtual shared_ptr<MovingObjects> Shoot() override;
    virtual void Kill() override;
    virtual bool Respawns() override;
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _enemyPos;
    Screen _screen;
    EnemyBullet _enemyBullet;
    float _EnemySpeed = 0.005;
    bool _IsAlive;
	bool _ObjectRespawns;
    float _CollisionRadius = 32;
};

#endif