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
    Player(Screen screen, int NumberOfLives);

    PlayerDirection GetDirection();
    virtual ObjectsPosition GetPosition() override;
    virtual Objects GetObject() override;
    virtual void Move() override;
    virtual bool Status() override;
    virtual shared_ptr<MovingObjects> Shoot() override;
    virtual bool Respawns() override;
    virtual void Kill() override;
    virtual float GetCollisionRadius() override;
    void setDirection(PlayerDirection direction);
    void ResetPlayer();
    bool GameOver();
    void WeaponUpgrade();
    bool CheckUpgrade();

private:
    ObjectsPosition _PlayerPosition;
    PlayerDirection _Direction;
    Screen _screen;
    int _NumberOfLives;
    PlayerBullet _PlayersBullet;
    bool _IsAlive;
    float _PlayerSpeed = 0.25;
    float _CollisionRadius = 64;
    int _bullets = 0;
    bool _upgrade;
};

#endif
