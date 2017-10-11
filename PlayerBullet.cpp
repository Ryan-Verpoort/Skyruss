#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(ObjectsPosition playerPos, Screen screen)
    : _playerBulletPos(playerPos)
    , _aliveStatus(true)
    , _screen(screen)
{
}

ObjectsPosition PlayerBullet::GetPosition()
{
    return _playerBulletPos;
}
Objects PlayerBullet::GetObject()
{
    return Objects::PlayerBullet;
}

bool PlayerBullet::Status()
{
    return _aliveStatus;
}

void PlayerBullet::Move()
{
    if(_playerBulletPos.GetRadius() > 15) {
	auto radiusFactor = _screen.getObjectRadius() * 0.001f;
	_playerBulletPos.setRadius(_playerBulletPos.GetRadius() - radiusFactor);
	auto rad = (_playerBulletPos.GetAngle() * PI / 180) * 0.5;
	newXPos = _screen.getScreenCentreX() + _playerBulletPos.GetRadius() * cos(rad - M_PI_2);
	newYPos = _screen.getScreenCentreY() - _playerBulletPos.GetRadius() * sin(rad - M_PI_2);
	_playerBulletPos.SetCurrentX(newXPos);
	_playerBulletPos.SetCurrentY(newYPos);
    } else {
	Kill();
    }
}

bool PlayerBullet::Respawns()
{
    return false;
}

void PlayerBullet::Kill()
{
    _aliveStatus = false;
}

float PlayerBullet::GetCollisionRadius()
{
    return _CollisionRadius;
}