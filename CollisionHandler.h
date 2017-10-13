#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "MovingObjects.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

/**
 * @class CollisionHandler
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file CollisionHandler.h
 * @brief Determination and handling of collision detection
 *
 * Used by all movement classes including the -enemy bullet and player bullet classes- to detect collisions with either
 * the Player or the Enemies
 * Used to chech Asteroid-Player collisions, Player bullet - Enemy collisions, Enemy bullet Player collisions,
 * Enemy-Player collisions, Satellite bullet - Player collisions
 */

class CollisionHandler
{

public:
    /**
     * @brief Used in identfying the collision distance of all objects redered within the screen window
     * @param Object_1
     * @param Object_2
     * @return  _Collision
     */
    float CollisionDetection(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);

    /**
     * @brief Responisible for checking Player collisions with other rendered objects
     *
     * Checks Player-Asteroid collisions
     * Checks Player-Enemy collisions
     * Checks Player bullet collisions
     * Checks Enemy bullet collisions
     * Checks Satellite bullet collisions
     * Assigns lives to Player object
     * @param GameObjects
     */
    void CheckForCollisions(vector<shared_ptr<MovingObjects> >& GameObjects);

private:
    /**
     * @brief Checks for Player collions with Enemies
     *
     * Used in identifying the collision status of rendered Player and Enemy crafts in order to delete those which must
     * be deleted. Additionally,
     * if collisions have occured it is responsible for subtracting a life from the current life count.
     * @param Object_1
     * @param Object_2
     */
    void PlayerEnemyCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);

    /**
     * @brief Checks for Player collions with Asteroid
     *
     * Used in identifying the collision status of rendered Player and Asteroid in order to delete both player and
     * Asteroid should collisions occure.Additionally,
     * if collisions have occured it is responsible for subtracting a life from the current life count.
     * @param Object_1
     * @param Object_2
     */
    void PlayerAsteroidCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);

    /**
     * @brief Checks for Player bullet collisions with Enemy crafts
     *
     * Used in indentifying collisions between Enemy and Player bullet, and deleting enemies should collisions occure.
     * @param Object_1
     * @param Object_2
     */
    void PlayerBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);

    /**
     * @brief Checks for Enemy bullet collisions with Player craft
     *
     * Used in indentifying collisions between Player and Enemy bullets, aeleting the Player should collisions occure,
     * and subtracting a life from the current life count
     * @param Object_1
     * @param Object_2
     */
    void EnemyBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);

    /**
     * @brief Checks for Satallite bullet collisions with Player craft
     *
     * Identifys collsions with Satalllite bullets and Player craft. In the event of a collsion, it is responsible for
     * deleting the Player object and subtracts a life from the current life count
     * @param Object_1
     * @param Object_2
     */
    void SatelliteBulletCollide(shared_ptr<MovingObjects>& Object_1, shared_ptr<MovingObjects>& Object_2);

    /**
     * @brief Sets the Life object to be called in functions
     * @param Object_2
     */
    void AssignLife(shared_ptr<MovingObjects>& Object_2);

    /**
    * @param Calculates and stores the collision distance between two objects
    */
    float _Collision;
    shared_ptr<MovingObjects> _life;
};

#endif
