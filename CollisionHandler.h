#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "MovingObjects.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class CollisionHandler
{

public:
    float CollisionDetection(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);
    void CheckForCollisions(vector<shared_ptr<MovingObjects> >& GameObjects);

private:
    void PlayerEnemyCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);
    void PlayerAsteroidCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);
    void PlayerBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);
    void EnemyBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);
    void SatelliteBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);
    void AssignLife(shared_ptr<MovingObjects>& Object_2);
    float _Collision;
    shared_ptr<MovingObjects> _life;
};

#endif
