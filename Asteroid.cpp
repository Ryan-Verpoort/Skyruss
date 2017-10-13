#include "Asteroid.h"

Asteroid::Asteroid(Screen screen)
    : _screen(screen)
{
    _IsAlive = true;
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
    return _IsAlive;
}

void Asteroid::Move()
{
    // Set The Speed which the Asteroid Moves
    float AsteroidSpeed = 0.5;

    // Calculate the Distance to the Player
    _DistToPlayer = sqrt((_PlayerXPos - _screen.getScreenCentreX()) * (_PlayerXPos - _screen.getScreenCentreX()) +
        (_PlayerYPos - _screen.getScreenCentreY()) * (_PlayerYPos - _screen.getScreenCentreY()));

    // Increment the X and Y values towards the Players position
    auto _xIncrement = AsteroidSpeed * (_PlayerXPos - _screen.getScreenCentreX()) / _DistToPlayer;
    auto _yIncrement = AsteroidSpeed * (_PlayerYPos - _screen.getScreenCentreY()) / _DistToPlayer;

    // Set the Current Position of the asteroid
    float _UpdateXPos = _AsteroidPos.GetCurrentX();
    float _UpdateYPos = _AsteroidPos.GetCurrentY();

    // Incremnet and Set the Current position of Asteroid towards the Player
    _UpdateXPos += _xIncrement;
    _UpdateYPos += _yIncrement;
    _AsteroidPos.SetCurrentX(_UpdateXPos);
    _AsteroidPos.SetCurrentY(_UpdateYPos);

    // Check The Position of the Asteroid is on the screen otherwise Kill Asteroid
    if(_AsteroidPos.GetCurrentX() >= _screen.getScreenWidth() || _AsteroidPos.GetCurrentY() <= 0) {
        Kill();
    } else if(_AsteroidPos.GetCurrentX() <= 0 || _AsteroidPos.GetCurrentY() >= _screen.getScreenHeight()) {
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
    _IsAlive = false;
}

void Asteroid::PlayersPos(shared_ptr<Player> _player)
{
    // Get The Player Position Which Asteroid Moves towards
    _PlayerXPos = _player->GetPosition().GetCurrentX();
    _PlayerYPos = _player->GetPosition().GetCurrentY();
}