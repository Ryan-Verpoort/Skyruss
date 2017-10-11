#ifndef ASTEROID_H
#define ASTEROID_H

#include "Screen.h"
#include "MovingObjects.h"
#include "Player.h"

#include <cmath>
#include <memory>
using std::shared_ptr;

class Asteroid : public MovingObjects
{
public:
    Asteroid(Screen screen);
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    void PlayersPos(shared_ptr<Player> _player);
    virtual void Move() override;
    virtual bool Status() override;
    virtual void Kill() override;
    virtual bool Respawns() override;
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _AsteroidPos;
    ObjectsPosition _PlayerPos;
    bool _aliveStatus;
    Screen _screen;
    bool _reSpawn;
    float _PlayerXPos;
    float _PlayerYPos;
    float _DistToPlayer;
    float _CollisionRadius = 64;
};

#endif