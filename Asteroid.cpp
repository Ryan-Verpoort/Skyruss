#include "Asteroid.h"

Asteroid::Asteroid(Screen screen)
    : _screen(screen)
{
    _aliveStatus = true;
    _AsteroidPos.setRadius(screen.getObjectRadius());
    _AsteroidPos.SetInitialX(screen.getScreenCentreX());
    _AsteroidPos.SetInitialY(screen.getScreenCentreY());
    _AsteroidPos.SetCurrentX(screen.getScreenCentreX());
    _AsteroidPos.SetCurrentY(screen.getScreenCentreY());
}

ObjectsPosition Asteroid::GetPosition()
{
    return _AsteroidPos;
}

Objects Asteroid::GetObject()
{
    return Objects::Asteroid;
}

bool Asteroid::Status()
{
    return _aliveStatus;
}

void Asteroid::Move()
{

    float AsteroidSpeed = 0.5;

    _DistToPlayer = sqrt((_PlayerXPos - _screen.getScreenCentreX()) * (_PlayerXPos - _screen.getScreenCentreX()) +
        (_PlayerYPos - _screen.getScreenCentreY()) * (_PlayerYPos - _screen.getScreenCentreY()));
    auto _xIncrement = AsteroidSpeed * (_PlayerXPos - _screen.getScreenCentreX()) / _DistToPlayer;
    auto _yIncrement = AsteroidSpeed * (_PlayerYPos - _screen.getScreenCentreY()) / _DistToPlayer;

    float xx = _AsteroidPos.GetCurrentX();
    float yy = _AsteroidPos.GetCurrentY();

    xx += _xIncrement;
    yy += _yIncrement;
    _AsteroidPos.SetCurrentX(xx);
    _AsteroidPos.SetCurrentY(yy);

    if(_AsteroidPos.GetCurrentX() >= _screen.getScreenWidth() || _AsteroidPos.GetCurrentY() <= 0) {
	Kill();
    }

    if(_AsteroidPos.GetCurrentX() <= 0 || _AsteroidPos.GetCurrentY() >= _screen.getScreenHeight()) {
	Kill();
    }
}

bool Asteroid::Respawns()
{
    return false;
}

float Asteroid::GetCollisionRadius()
{
    return _CollisionRadius;
}

void Asteroid::Kill()
{
    _aliveStatus = false;
}

void Asteroid::PlayersPos(shared_ptr<Player> _player)
{
    _PlayerXPos = _player->GetPosition().GetCurrentX();
    _PlayerYPos = _player->GetPosition().GetCurrentY();
}