#include "CollisionHandler.h"

// Get the Distance Between Objects to Check if overlap and therefore Collide
float CollisionHandler::CollisionDetection(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    return _Collision = abs(Object_1->GetPosition().GetCurrentX() - Object_2->GetPosition().GetCurrentX()) +
        abs(Object_1->GetPosition().GetCurrentY() - Object_2->GetPosition().GetCurrentY());
}

void CollisionHandler::CheckForCollisions(vector<shared_ptr<MovingObjects> >& Objects)
{
    // For All Objects Check For Collisions
    for(auto& Object_1 : Objects) {
        for(auto& Object_2 : Objects) {
            AssignLife(Object_2);
            PlayerEnemyCollide(Object_1, Object_2);
            PlayerAsteroidCollide(Object_1, Object_2);
            PlayerBulletCollide(Object_1, Object_2);
            EnemyBulletCollide(Object_1, Object_2);
            SatelliteBulletCollide(Object_1, Object_2);
        }
    }
}

void CollisionHandler::PlayerEnemyCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    // Get Objects Distance from each Other
    _Collision = CollisionDetection(Object_1, Object_2);

    // Check that the objects are correct
    if(Object_1->GetObject() == Objects::Player && Object_2->GetObject() == Objects::Enemy) {

        // If Objects Overlap/Collide Kill The objects and Delete A Life
        if(_Collision < Object_2->GetCollisionRadius()) {
            Object_1->Kill();
            Object_2->Kill();
            _life->Kill();
        }
    }
}

void CollisionHandler::PlayerAsteroidCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    // Get Objects Distance from each Other
    _Collision = CollisionDetection(Object_1, Object_2);

    // Check that the objects are correct
    if(Object_1->GetObject() == Objects::Player && Object_2->GetObject() == Objects::Asteroid) {

        // If Objects Overlap/Collide Kill The objects and Delete A Life Asteroid Does not get destroyed
        if(_Collision < Object_2->GetCollisionRadius()) {
            Object_1->Kill();
            _life->Kill();
        }
    }
}

void CollisionHandler::PlayerBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    // Get Objects Distance from each Other
    _Collision = CollisionDetection(Object_1, Object_2);

    // Check that the objects are correct
    if(Object_1->GetObject() == Objects::Player && Object_2->GetObject() == Objects::EnemyBullet) {

        // If Objects Overlap/Collide Kill The objects and Delete A Life
        if(_Collision < Object_2->GetCollisionRadius()) {
            Object_1->Kill();
            Object_2->Kill();
            _life->Kill();
        }
    }
}

void CollisionHandler::EnemyBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    // Get Objects Distance from each Other
    _Collision = CollisionDetection(Object_1, Object_2);

    // Check that the objects are correct
    if(Object_1->GetObject() == Objects::Enemy && Object_2->GetObject() == Objects::PlayerBullet) {

        // If Objects Overlap/Collide Kill The objects
        if(_Collision < Object_2->GetCollisionRadius()) {
            Object_1->Kill();
            Object_2->Kill();
        }
    }
}

void CollisionHandler::SatelliteBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    // Get Objects Distance from each Other
    _Collision = CollisionDetection(Object_1, Object_2);

    // Check that the objects are correct
    if(Object_1->GetObject() == Objects::Satellites && Object_2->GetObject() == Objects::PlayerBullet) {

        // If Objects Overlap/Collide Kill The objects
        if(_Collision < Object_2->GetCollisionRadius()) {
            Object_1->Kill();
            Object_2->Kill();
        }
    }
}

void CollisionHandler::AssignLife(shared_ptr<MovingObjects>& Object_2)
{
    // Set Life Object to be used in the functions
    if(Object_2->GetObject() == Objects::Life) {
        _life = Object_2;
    }
}