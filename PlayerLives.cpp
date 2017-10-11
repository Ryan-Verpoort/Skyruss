#include "PlayerLives.h"

PlayerLives::PlayerLives(Screen screen, int NumberOfLives)
    : _screen(screen)
{
    _aliveStatus = true;
    _LivesPos.SetCurrentX(20 + 50 * (NumberOfLives - 1));
    _LivesPos.SetCurrentY(20);
}

ObjectsPosition PlayerLives::GetPosition()
{
    return _LivesPos;
}

Objects PlayerLives::GetObject()
{
    return Objects::Life;
}

void PlayerLives::Move()
{
}

bool PlayerLives::Status()
{
    return _aliveStatus;
}

bool PlayerLives::Respawns()
{
    return false;
}

void PlayerLives::Kill()
{
    _aliveStatus = false;
}

float PlayerLives::GetCollisionRadius()
{
    return _CollisionRadius;
}