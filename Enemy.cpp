#include "Enemy.h"

Enemy::Enemy(Screen screen)
    : _screen(screen)
    , _enemyBullet(_enemyPos, screen)
{
    _aliveStatus = true;
    _reSpawn = false;
    int randomStartAngle = rand() % 360;
    _enemyPos.setAngle(randomStartAngle);
    _enemyPos.setRadius(screen.getObjectRadius());
    _enemyPos.SetInitialX(screen.getScreenCentreX());
    _enemyPos.SetInitialY(screen.getScreenCentreY());
    _enemyPos.SetCurrentX(screen.getScreenCentreX());
    _enemyPos.SetCurrentY(screen.getScreenCentreY());
}

ObjectsPosition Enemy::GetPosition()
{
    return _enemyPos;
}

Objects Enemy::GetObject()
{
    return Objects::Enemy;
}

void Enemy::Move()
{
    auto radianAngle = (_enemyPos.GetAngle() * PI / 180);
    _enemyPos.SetCurrentX(_enemyPos.GetInitialX() + _factor * _enemyPos.GetRadius() * cos(radianAngle));
    _enemyPos.SetCurrentY(_enemyPos.GetInitialY() + _factor * _enemyPos.GetRadius() * sin(radianAngle));
    _factor += 0.0005;

    int xLimit = abs(_enemyPos.GetCurrentX());
    int yLimit = abs(_enemyPos.GetCurrentY());
    if(xLimit > _enemyPos.GetInitialX() + _enemyPos.GetRadius() ||
        yLimit > _enemyPos.GetInitialY() + _enemyPos.GetRadius()) {
	_aliveStatus = false;
	_reSpawn = true;
    }

    if(xLimit < _enemyPos.GetInitialX() - _enemyPos.GetRadius() ||
        yLimit < _enemyPos.GetInitialY() - _enemyPos.GetRadius()) {
	_aliveStatus = false;
	_reSpawn = true;
    }
}

bool Enemy::Status()
{
    return _aliveStatus;
}

shared_ptr<MovingObjects> Enemy::Shoot()
{
    return std::make_shared<EnemyBullet>(_enemyPos, _screen);
}

bool Enemy::Respawns()
{
    return _reSpawn;
}

void Enemy::Kill()
{
    _aliveStatus = false;
}

float Enemy::GetCollisionRadius()
{
    return _CollisionRadius;
}