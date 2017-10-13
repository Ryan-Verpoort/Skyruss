#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(ObjectsPosition enemyPos, Screen screen)
    : _enemyBulletPos(enemyPos)
    , _IsAlive(true)
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
    return _IsAlive;
}

void EnemyBullet::Move()
{
    // Convert Degrees To Radians
    auto rad = (_enemyBulletPos.GetAngle() * PI / 180);

    // Move Enenmy Bullet Using Trig as with Enemy Class
    _enemyBulletPos.SetCurrentX(
        _enemyBulletPos.GetInitialX() + _EnemyBulletSpeed * _screen.getObjectRadius() * cos(rad));
    _enemyBulletPos.SetCurrentY(
        _enemyBulletPos.GetInitialY() + _EnemyBulletSpeed * _screen.getObjectRadius() * sin(rad));
    _EnemyBulletSpeed += 0.001;

    // Check Enemy Bullet Is still on Screen otherwise Kill object
    if((_enemyBulletPos.GetCurrentX() >= _screen.getScreenWidth()) ||
        (_enemyBulletPos.GetCurrentY() >= _screen.getScreenHeight()) || (_enemyBulletPos.GetCurrentX() <= 0) ||
        (_enemyBulletPos.GetCurrentY() <= 0)) {
        Kill();
    }
}

bool EnemyBullet::Respawns()
{
    return false;
}

void EnemyBullet::Kill()
{
    _IsAlive = false;
}

float EnemyBullet::GetCollisionRadius()
{
    return _CollisionRadius;
}