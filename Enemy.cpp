#include "Enemy.h"

Enemy::Enemy(Screen screen)
    : _screen(screen)
    , _enemyBullet(_enemyPos, screen)
{
    _IsAlive = true;
    _ObjectRespawns = false;

    // Generate Random Start Angle for Movement
    int RandomAngle = rand() % 361;
    _enemyPos.setAngle(RandomAngle);
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
    // Convert Angle from Degrees to radians
    auto Radians = (_enemyPos.GetAngle() * PI / 180);

    // Move Enemy X related to Cosine and Y related to Sine From Trig rules
    _enemyPos.SetCurrentX(_enemyPos.GetInitialX() + _EnemySpeed * _enemyPos.GetRadius() * cos(Radians));
    _enemyPos.SetCurrentY(_enemyPos.GetInitialY() + _EnemySpeed * _enemyPos.GetRadius() * sin(Radians));
    _EnemySpeed += 0.0005;

    // Check Objects Position if off Screen Delete
    if((_enemyPos.GetCurrentX() > _screen.getScreenWidth()) || (_enemyPos.GetCurrentY() > _screen.getScreenHeight()) ||
        (_enemyPos.GetCurrentX() < 0) || (_enemyPos.GetCurrentY() < 0)) {
	Kill();
	_ObjectRespawns = true;
    }
}

bool Enemy::Status()
{
    return _IsAlive;
}

shared_ptr<MovingObjects> Enemy::Shoot()
{
    // Give Enemy Position to Enemy Bullet Class
    return std::make_shared<EnemyBullet>(_enemyPos, _screen);
}

bool Enemy::Respawns()
{
    return _ObjectRespawns;
}

void Enemy::Kill()
{
    _IsAlive = false;
}

float Enemy::GetCollisionRadius()
{
    return _CollisionRadius;
}