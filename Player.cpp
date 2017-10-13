#include "Player.h"
#include <iostream>

Player::Player(Screen screen, int NumberOfLives)
    : _screen(screen)
    , _NumberOfLives(NumberOfLives)
    , _PlayersBullet(_PlayerPosition, _screen)
    , _IsAlive(true)
    , _upgrade(false)
{

    // Set Direction to Hold position
    _Direction = PlayerDirection::Hold;
    _PlayerPosition.setAngle(0);
    _PlayerPosition.SetCurrentX(screen.getScreenCentreX());
    _PlayerPosition.SetCurrentY(screen.getScreenCentreY() + screen.getObjectRadius());
    _PlayerPosition.setRadius(screen.getObjectRadius());
    _PlayerPosition.SetInitialX(screen.getScreenCentreX());
    _PlayerPosition.SetInitialY(screen.getScreenCentreY());
}

ObjectsPosition Player::GetPosition()
{
    return _PlayerPosition;
}

Objects Player::GetObject()
{
    return Objects::Player;
}

void Player::Move()
{
    // Check Direction And Move Accordingly
    if(GetDirection() == PlayerDirection::Clockwise)
        _PlayerPosition.setAngle(_PlayerPosition.GetAngle() - _PlayerSpeed);
    else if(GetDirection() == PlayerDirection::Anticlockwise)
        _PlayerPosition.setAngle(_PlayerPosition.GetAngle() + _PlayerSpeed);

    // Convert Degrees to Radians
    auto Radians = (_PlayerPosition.GetAngle() * PI / 180) * 0.5;

    // Move Player X related to Cosine and Y related to Sine From Trig rules
    _PlayerPosition.SetCurrentX(
        _PlayerPosition.GetInitialX() + _PlayerPosition.GetRadius() * cos(Radians - ANGLE_OFFSET));

    _PlayerPosition.SetCurrentY(
        _PlayerPosition.GetInitialY() - _PlayerPosition.GetRadius() * sin(Radians - ANGLE_OFFSET));
}
shared_ptr<MovingObjects> Player::Shoot()
{
    // Create New Objects Position Which is the same as Players Position So Players position Is not effected
    ObjectsPosition Bullets = _PlayerPosition;

    // Check Value of Bullets Allows for weapon upgrade bullets have a distance between them
    if(_bullets == 2) {
        // Move the bullet back behind Enemy
        Bullets.setRadius(Bullets.GetRadius() - 50);
        _bullets = 0;
    } else {
        Bullets.setRadius(Bullets.GetRadius());
    }
    _bullets++;

    // Pass the Position to Players bullets class
    return std::make_shared<PlayerBullet>(Bullets, _screen);
}

bool Player::Status()
{
    return _IsAlive;
}

PlayerDirection Player::GetDirection()
{
    return _Direction;
}

void Player::setDirection(PlayerDirection direction)
{
    _Direction = direction;
}

bool Player::Respawns()
{
    return false;
}

void Player::Kill()
{
    _IsAlive = false;

    // Reset Players position
    ResetPlayer();
}

float Player::GetCollisionRadius()
{
    return _CollisionRadius;
}

void Player::ResetPlayer()
{
    // Decrease Lives remaining
    _NumberOfLives--;

    // Reset Players Status to true
    _IsAlive = true;

    // Reset Starting Position and direction to hold position
    _Direction = PlayerDirection::Hold;
    _PlayerPosition.setAngle(0);
    _PlayerPosition.SetCurrentX(_screen.getScreenCentreX());
    _PlayerPosition.SetCurrentY(_screen.getScreenCentreY() + _screen.getObjectRadius());
    _PlayerPosition.setRadius(_screen.getObjectRadius());
    _PlayerPosition.SetInitialX(_screen.getScreenCentreX());
    _PlayerPosition.SetInitialY(_screen.getScreenCentreY());

    // Change upgrade to false since player died losses Upgrade
    _upgrade = false;
}

bool Player::GameOver()
{
    // If Player has no more Lives the Game is over
    if(_NumberOfLives < 0) {
        return true;
    } else {
        return false;
    }
}

void Player::WeaponUpgrade()
{
    // Set upgrade to true
    _upgrade = true;
}

bool Player::CheckUpgrade()
{
    return _upgrade;
}