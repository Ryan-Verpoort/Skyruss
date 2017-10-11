#include "CollisionHandler.h"

float CollisionHandler::CollisionDetection(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    return _Collision = abs(Object_1->GetPosition().GetCurrentX() - Object_2->GetPosition().GetCurrentX()) +
        abs(Object_1->GetPosition().GetCurrentY() - Object_2->GetPosition().GetCurrentY());
}

void CollisionHandler::CheckForCollisions(vector<shared_ptr<MovingObjects> >& Objects)
{
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
    _Collision = CollisionDetection(Object_1, Object_2);
    if(Object_1->GetObject() == Objects::Player && Object_2->GetObject() == Objects::Enemy) {
	if(_Collision < Object_2->GetCollisionRadius()) {
	    Object_1->Kill();
	    Object_2->Kill();
	    _life->Kill();
	}
    }
}

void CollisionHandler::PlayerAsteroidCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    _Collision = CollisionDetection(Object_1, Object_2);
    if(Object_1->GetObject() == Objects::Player && Object_2->GetObject() == Objects::Asteroid) {
	if(_Collision < Object_2->GetCollisionRadius()) {
	    Object_1->Kill();
	    // Object_2->Kill();
	    _life->Kill();
	}
    }
}

void CollisionHandler::PlayerBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    _Collision = CollisionDetection(Object_1, Object_2);
    if(Object_1->GetObject() == Objects::Player && Object_2->GetObject() == Objects::EnemyBullet) {
	if(_Collision < Object_2->GetCollisionRadius()) {
	    Object_1->Kill();
	    Object_2->Kill();
	    _life->Kill();
	}
    }
}

void CollisionHandler::EnemyBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    _Collision = CollisionDetection(Object_1, Object_2);
    if(Object_1->GetObject() == Objects::Enemy && Object_2->GetObject() == Objects::PlayerBullet) {
	if(_Collision < Object_2->GetCollisionRadius()) {
	    Object_1->Kill();
	    Object_2->Kill();
	}
    }
}

void CollisionHandler::SatelliteBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2)
{
    _Collision = CollisionDetection(Object_1, Object_2);
    if(Object_1->GetObject() == Objects::Satellites && Object_2->GetObject() == Objects::PlayerBullet) {
	if(_Collision < Object_2->GetCollisionRadius()) {
	    Object_1->Kill();
	    Object_2->Kill();
	}
    }
}

void CollisionHandler::AssignLife(shared_ptr<MovingObjects>& Object_2)
{
    if(Object_2->GetObject() == Objects::Life) {
	_life = Object_2;
    }
}