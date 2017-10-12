#include "PlayerLives.h"

PlayerLives::PlayerLives(Screen screen, int NumberOfLives)
    : _screen(screen)
    , _IsAlive(true)
{
    // Set Lives Positon to Top Left Corner and increment x position
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
    // Lives do not move but Move function needed
}

bool PlayerLives::Status()
{
    return _IsAlive;
}

bool PlayerLives::Respawns()
{
    return false;
}

void PlayerLives::Kill()
{
    _IsAlive = false;
}

float PlayerLives::GetCollisionRadius()
{
    // Does not Collide But again Needed
    return _CollisionRadius;
}