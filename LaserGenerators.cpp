#include "LaserGenerators.h"

LaserGenerators::LaserGenerators(Screen screen)
    : _screen(screen)
{
    _IsAlive = true;
    _LaserGeneratorsPos.setRadius(Radius);
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
    _LaserGeneratorsPos.setAngle(_LaserGeneratorsPos.GetAngle() + _LaserSpeed);

    // Set New Co-Ordinates for Laser Generators Move
    _LaserGeneratorsPos.SetCurrentX(
        _LaserGeneratorsPos.GetInitialX() + _LaserGeneratorsPos.GetRadius() * cos(_LaserGeneratorsPos.GetAngle()));
    _LaserGeneratorsPos.SetCurrentY(
        _LaserGeneratorsPos.GetInitialY() + _LaserGeneratorsPos.GetRadius() * sin(_LaserGeneratorsPos.GetAngle()));

    // Check The Position of the LaserGenerators is on the screen otherwise Kill LaserGenerators
    if(_LaserGeneratorsPos.GetRadius() >= _screen.getObjectRadius()) {

	Radius -= 0.03;
    } else {
	Radius += 0.03;
    }

    _LaserGeneratorsPos.setRadius(Radius);
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