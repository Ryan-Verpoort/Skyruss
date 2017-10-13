#include "Satellite.h"

Satellite::Satellite(Screen screen, int NumberOfSats)
    : _screen(screen)
    , _enemyBullet(_satellitePos, screen)
    , _IsAlive(true)
{

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
    _satellitePos.setAngle(_satellitePos.GetAngle() + _SatelliteSpeed);

    // Set New Co-Ordinates for Satellite Move
    _satellitePos.SetCurrentX(_satellitePos.GetInitialX() + _satellitePos.GetRadius() * cos(_satellitePos.GetAngle()));
    _satellitePos.SetCurrentY(_satellitePos.GetInitialY() + _satellitePos.GetRadius() * sin(_satellitePos.GetAngle()));
}

shared_ptr<MovingObjects> Satellite::Shoot()
{
    // Set Satellite Bullets Position to be same as Satellite
    _SatelliteBullet = _satellitePos;

    // Set Angle to Players Angle for Bullet position
    _SatelliteBullet.setAngle(_PlayerAngle);
    return std::make_shared<EnemyBullet>(_SatelliteBullet, _screen);
}

bool Satellite::Status()
{
    return _IsAlive;
}

bool Satellite::Respawns()
{
    return false;
}

void Satellite::Kill()
{
    _IsAlive = false;
}

float Satellite::GetCollisionRadius()
{
    return _CollisionRadius;
}

void Satellite::PlayersPos(shared_ptr<Player> _player)
{
    // Get Players Current Co-Ordiantes
    _PlayerXPos = _player->GetPosition().GetCurrentX();
    _PlayerYPos = _player->GetPosition().GetCurrentY();

    // Check Which Quadrant Player is in and Set Satellite Position Accordingly
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

    // Set Satellites position
    _satellitePos.SetInitialX(_PlayerXPos);
    _satellitePos.SetInitialY(_PlayerYPos);
    _satellitePos.SetCurrentX(_PlayerXPos);
    _satellitePos.SetCurrentY(_PlayerYPos);

    // Get Players Angle For Bullet position
    _PlayerAngle = _player->GetPosition().GetAngle();
}