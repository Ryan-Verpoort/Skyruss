#include "LaserGenerators.h"

LaserGenerators::LaserGenerators(Screen screen)
    : _screen(screen)
{
    _IsAlive = true;
    _LaserGeneratorsPos.setRadius(screen.getObjectRadius());
    _LaserGeneratorsPos.SetInitialX(screen.getScreenCentreX());
    _LaserGeneratorsPos.SetInitialY(screen.getScreenCentreY());
    _LaserGeneratorsPos.SetCurrentX(screen.getScreenCentreX());
    _LaserGeneratorsPos.SetCurrentY(screen.getScreenCentreY());
}

ObjectsPosition LaserGenerators::GetPosition()
{
    return _LaserGeneratorsPos;
}

Objects LaserGenerators::GetObject()
{
    return Objects::LaserGenerators;
}

bool LaserGenerators::Status()
{
    return _IsAlive;
}

void LaserGenerators::Move()
{
    // Set The Speed which the LaserGenerators Moves
    float LaserGeneratorsSpeed = 0.2;

    _LaserGeneratorsPos.setAngle(_PlayerAngle);
    // Calculate the Distance to the Player
    _DistToPlayer = sqrt((_PlayerXPos - _screen.getScreenCentreX()) * (_PlayerXPos - _screen.getScreenCentreX()) +
        (_PlayerYPos - _screen.getScreenCentreY()) * (_PlayerYPos - _screen.getScreenCentreY()));

    // Increment the X and Y values towards the Players position
    auto _xIncrement = LaserGeneratorsSpeed * (_PlayerXPos - _screen.getScreenCentreX()) / _DistToPlayer;
    auto _yIncrement = LaserGeneratorsSpeed * (_PlayerYPos - _screen.getScreenCentreY()) / _DistToPlayer;

    // Set the Current Position of the asteroid
    float _UpdateXPos = _LaserGeneratorsPos.GetCurrentX();
    float _UpdateYPos = _LaserGeneratorsPos.GetCurrentY();

    // Incremnet and Set the Current position of LaserGenerators towards the Player
    _UpdateXPos += _xIncrement;
    _UpdateYPos += _yIncrement;
    _LaserGeneratorsPos.SetCurrentX(_UpdateXPos);
    _LaserGeneratorsPos.SetCurrentY(_UpdateYPos);

    // Check The Position of the LaserGenerators is on the screen otherwise Kill LaserGenerators
    if(_LaserGeneratorsPos.GetCurrentX() >= _screen.getScreenWidth() || _LaserGeneratorsPos.GetCurrentY() <= 0) {
	Kill();
    } else if(_LaserGeneratorsPos.GetCurrentX() <= 0 ||
        _LaserGeneratorsPos.GetCurrentY() >= _screen.getScreenHeight()) {
	Kill();
    }
}

bool LaserGenerators::Respawns()
{
    return false;
}

float LaserGenerators::GetCollisionRadius()
{
    return _CollisionRadius;
}

void LaserGenerators::Kill()
{
    _IsAlive = false;
}

void LaserGenerators::PlayersPos(shared_ptr<Player> _player)
{
    // Get The Player Position Which LaserGenerators Moves towards
    _PlayerXPos = _player->GetPosition().GetCurrentX();
    _PlayerYPos = _player->GetPosition().GetCurrentY();
    _PlayerAngle = _player->GetPosition().GetAngle();
}