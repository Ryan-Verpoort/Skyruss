#include "Player.h"
#include <iostream>

Player::Player(Screen screen)
    : _screen(screen)
    , _PlayersBullet(_PlayerPosition, _screen)
{
    _lives = 3;
    _bullets = 0;
    _aliveStatus = true;
    _Direction = PlayerDirection::Hold;
    _PlayerPosition.setAngle(0);
    _PlayerPosition.SetCurrentX(screen.getScreenCentreX());
    _PlayerPosition.SetCurrentY(screen.getScreenCentreY() + screen.getObjectRadius());
    _PlayerPosition.setRadius(screen.getObjectRadius());
    _PlayerPosition.SetInitialX(screen.getScreenCentreX());
    _PlayerPosition.SetInitialY(screen.getScreenCentreY());
}

ObjectsPosition Player::GetPosition()
{
    return _PlayerPosition;
}

Objects Player::GetObject()
{
    return Objects::Player;
}

void Player::Move()
{

    if(GetDirection() == PlayerDirection::Clockwise)
	_PlayerPosition.setAngle(_PlayerPosition.GetAngle() - 0.25);
    else if(GetDirection() == PlayerDirection::Anticlockwise)
	_PlayerPosition.setAngle(_PlayerPosition.GetAngle() + 0.25);

    auto radianAngle = (_PlayerPosition.GetAngle() * PI / 180) * 0.5;
    int newXPos = _PlayerPosition.GetInitialX() + _PlayerPosition.GetRadius() * cos(radianAngle - ANGLE_OFFSET);
    int newYPos = _PlayerPosition.GetInitialY() - _PlayerPosition.GetRadius() * sin(radianAngle - ANGLE_OFFSET);
    _PlayerPosition.SetCurrentX(newXPos);
    _PlayerPosition.SetCurrentY(newYPos);
}
shared_ptr<MovingObjects> Player::Shoot()
{
    ObjectsPosition Bullets = _PlayerPosition;
    if(_bullets == 2) {
	Bullets.setRadius(Bullets.GetRadius() - 50);
	_bullets = 0;
    } else {
	Bullets.setRadius(Bullets.GetRadius());
    }
    _bullets++;
    return std::make_shared<PlayerBullet>(Bullets, _screen);
}

bool Player::Status()
{
    return _aliveStatus;
}

PlayerDirection Player::GetDirection()
{
    return _Direction;
}

void Player::setDirection(PlayerDirection direction)
{
    _Direction = direction;
}

bool Player::Respawns()
{
    return false;
}

void Player::Kill()
{
    _aliveStatus = false;
    Respawn();
}

float Player::GetCollisionRadius()
{
    return _CollisionRadius;
}

void Player::Respawn()
{
    _lives--;
    _aliveStatus = true;
    _Direction = PlayerDirection::Hold;
    _PlayerPosition.setAngle(0);
    _PlayerPosition.SetCurrentX(_screen.getScreenCentreX());
    _PlayerPosition.SetCurrentY(_screen.getScreenCentreY() + _screen.getObjectRadius());
    _PlayerPosition.setRadius(_screen.getObjectRadius());
    _PlayerPosition.SetInitialX(_screen.getScreenCentreX());
    _PlayerPosition.SetInitialY(_screen.getScreenCentreY());
}

bool Player::isGameOver()
{
    if(_lives < 0) {
	return true;
    } else {
	return false;
    }
}