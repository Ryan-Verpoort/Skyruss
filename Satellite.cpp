#include "Satellite.h"

Satellite::Satellite(Screen screen, int NumberOfSats)
    : _screen(screen)
    , _enemyBullet(_satellitePos, screen)
{
    _aliveStatus = true;
    int startingPosition = 0;
    if(NumberOfSats == 1) {
	startingPosition = 0;
    } else if(NumberOfSats == 2) {
	startingPosition = 2.1;
    } else {
	startingPosition = 4.2;
    }

    _satellitePos.setAngle(startingPosition);
    _satellitePos.setRadius(50);
}

ObjectsPosition Satellite::GetPosition()
{
    return _satellitePos;
}

Objects Satellite::GetObject()
{
    return Objects::Satellites;
}

void Satellite::Move()
{
    _satellitePos.setAngle(_satellitePos.GetAngle() + 0.00025);
    int newXPos = _satellitePos.GetInitialX() + _satellitePos.GetRadius() * cos(_satellitePos.GetAngle());
    int newYPos = _satellitePos.GetInitialY() + _satellitePos.GetRadius() * sin(_satellitePos.GetAngle());
    _satellitePos.SetCurrentX(newXPos);
    _satellitePos.SetCurrentY(newYPos);
}

shared_ptr<MovingObjects> Satellite::Shoot()
{
    return std::make_shared<EnemyBullet>(_satellitePos, _screen);
}

bool Satellite::Status()
{
    return _aliveStatus;
}

bool Satellite::Respawns()
{
    return false;
}

void Satellite::Kill()
{
    _aliveStatus = false;
}

float Satellite::GetCollisionRadius()
{
    return _CollisionRadius;
}

void Satellite::PlayersPos(shared_ptr<Player> _player)
{
    //_PlayerAngle = _player->GetPosition().GetAngle();
    _PlayerXPos = _player->GetPosition().GetCurrentX();
    _PlayerYPos = _player->GetPosition().GetCurrentY();

    if(_PlayerXPos >= _screen.getScreenCentreX()) {
	_PlayerXPos = _PlayerXPos - 100;
    } else {
	_PlayerXPos = _PlayerXPos + 100;
    }
    if(_PlayerYPos >= _screen.getScreenCentreY()) {
	_PlayerYPos = _PlayerYPos - 100;
    } else {
	_PlayerYPos = _PlayerYPos + 100;
    }

    _satellitePos.SetInitialX(_PlayerXPos);
    _satellitePos.SetInitialY(_PlayerYPos);
    _satellitePos.SetCurrentX(_PlayerXPos);
    _satellitePos.SetCurrentY(_PlayerYPos);
}