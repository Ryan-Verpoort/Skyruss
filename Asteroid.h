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
	
	//Functions Inherited From MovinObjects Class
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual void Move() override;
    virtual bool Status() override;
    virtual void Kill() override;
    virtual bool Respawns() override;
    virtual float GetCollisionRadius() override;
	
	//Get Players Position to move towards player
	void PlayersPos(shared_ptr<Player> _player);

private:
    ObjectsPosition _AsteroidPos;
    ObjectsPosition _PlayerPos;
    bool _IsAlive;
    Screen _screen;
    float _PlayerXPos;
    float _PlayerYPos;
    float _DistToPlayer;
    float _CollisionRadius = 64;
};

#endif