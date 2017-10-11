#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(ObjectsPosition enemyPos, Screen screen)
    : _enemyBulletPos(enemyPos)
    , _aliveStatus(true)
    , _screen(screen)
{
    _enemyBulletPos.setAngle(enemyPos.GetAngle());
    _enemyBulletPos.setRadius(enemyPos.GetRadius());
    _enemyBulletPos.SetInitialX(enemyPos.GetCurrentX());
    _enemyBulletPos.SetInitialY(enemyPos.GetCurrentY());
    _enemyBulletPos.SetCurrentX(enemyPos.GetCurrentX());
    _enemyBulletPos.SetCurrentY(enemyPos.GetCurrentY());
}

ObjectsPosition EnemyBullet::GetPosition()
{
    return _enemyBulletPos;
}

Objects EnemyBullet::GetObject()
{
    return Objects::EnemyBullet;
}

bool EnemyBullet::Status()
{
    return _aliveStatus;
}

void EnemyBullet::Move()
{

    auto rad = (_enemyBulletPos.GetAngle() * PI / 180);
    _enemyBulletPos.SetCurrentX(_enemyBulletPos.GetInitialX() + _factor * _screen.getObjectRadius() * cos(rad));
    _enemyBulletPos.SetCurrentY(_enemyBulletPos.GetInitialY() + _factor * _screen.getObjectRadius() * sin(rad));
    _factor += 0.001;

    if(_enemyBulletPos.GetCurrentX() >= _screen.getScreenWidth() || _enemyBulletPos.GetCurrentY() <= 0) {
	Kill();
    }

    if(_enemyBulletPos.GetCurrentX() <= 0 || _enemyBulletPos.GetCurrentY() >= _screen.getScreenHeight()) {
	Kill();
    }
}

bool EnemyBullet::Respawns()
{
    return false;
}

void EnemyBullet::Kill()
{
    _aliveStatus = false;
}

float EnemyBullet::GetCollisionRadius()
{
    return _CollisionRadius;
}