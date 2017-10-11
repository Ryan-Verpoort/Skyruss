#ifndef SATELLITE_H
#define SATELLITE_H

#include "Screen.h"
#include "ShootingObjects.h"
#include "EnemyBullet.h"
#include "Player.h"

#include <memory>
using std::shared_ptr;

class Satellite : public ShootingObjects
{
public:
    Satellite(Screen screen, int NumberOfSats);
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual bool Status() override;
    virtual void Move() override;
    virtual shared_ptr<MovingObjects> Shoot();
    virtual bool Respawns() override;
    virtual void Kill() override;
    virtual float GetCollisionRadius() override;
    void PlayersPos(shared_ptr<Player> _player);

private:
    ObjectsPosition _satellitePos;
    Screen _screen;
    EnemyBullet _enemyBullet;
    float _factor = 0.005;
    bool _aliveStatus;
    float _CollisionRadius = 64;
    float _PlayerAngle;
    float _PlayerXPos;
    float _PlayerYPos;
};
#endif