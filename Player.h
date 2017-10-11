#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerBullet.h"
#include "PlayerDirection.h"
#include "PlayerLives.h"
#include "Screen.h"
#include "ShootingObjects.h"

class Player : public ShootingObjects
{

public:
    Player(Screen screen);

    PlayerDirection GetDirection();
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual void Move() override;
    virtual bool Status() override;
    virtual shared_ptr<MovingObjects> Shoot() override;
    void setDirection(PlayerDirection direction);
    virtual bool Respawns() override;
    virtual void Kill() override;
    virtual float GetCollisionRadius() override;
    bool isGameOver();
    void WeaponUpgrade();

private:
    void Respawn();
    ObjectsPosition _PlayerPosition;
    bool _aliveStatus;
    PlayerDirection _Direction;
    Screen _screen;
    PlayerBullet _PlayersBullet;
    bool _reSpawn;
    float _CollisionRadius = 64;
    int _lives;
	int _bullets;
};

#endif
