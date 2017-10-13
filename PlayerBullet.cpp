#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(ObjectsPosition playerPos, Screen screen)
    : _playerBulletPos(playerPos)
    , _IsAlive(true)
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
    return _IsAlive;
}

void PlayerBullet::Move()
{
    // Check if bullet is at centre of screen if it is kill
    if(_playerBulletPos.GetRadius() > 5) {
	auto _PlayerbulletSpeed = _screen.getObjectRadius() * 0.001f;

	// Move Bullet towards centre of Screen
	_playerBulletPos.setRadius(_playerBulletPos.GetRadius() - _PlayerbulletSpeed);

	// Change Degrees to Radians
	auto Radians = (_playerBulletPos.GetAngle() * PI / 180) * 0.5;

	// Move Bullet using Trig As in Player
	_playerBulletPos.SetCurrentX(_screen.getScreenCentreX() + _playerBulletPos.GetRadius() * cos(Radians - M_PI_2));
	_playerBulletPos.SetCurrentY(_screen.getScreenCentreY() - _playerBulletPos.GetRadius() * sin(Radians - M_PI_2));
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
    _IsAlive = false;
}

float PlayerBullet::GetCollisionRadius()
{
    return _CollisionRadius;
}