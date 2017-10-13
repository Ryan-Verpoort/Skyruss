#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "MovingObjects.h"
#include "ShootingObjects.h"
#include "Screen.h"
#include "Player.h"

#include <cmath>
#include <memory>
using std::shared_ptr;

/**
 * @class EnemyBullet
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file EnemyBullet.h
 * @brief Enemy Bullet Class
 *
 * Responsible for the positional rendering and movement mechanics of all bullets created for the Enemy object given the
 * current position of the Enemy craft
 */
class EnemyBullet : public MovingObjects
{
public:
    /**
     * @brief Default constructor for the EnemyBullet class
     *
     * Allows for the creation of all Enemy Bullets. On every game loop funtions are called in order to query and
     * evaluate the current
     * on-screen status of the bullet to be used during collision detection
     * Sets the inital and current x and y positions of the bullet to the current and initial x and y positions of its
     * rendered Enemy
     * Sets the angle of the bullet to be the same as the Enemy at time of creation
     * Sets the radius of the bullet for collision detection
     * @param enemyPos
     * @param screen
     */
    EnemyBullet(ObjectsPosition enemyPos, Screen screen);

    /**
     * @brief Returns the current position of the fired Enemy bullet
     * @return _enemyBulletPos
     */
    virtual ObjectsPosition GetPosition() override;

    /**
     * @brief Returns object of type EnemyBullet
     * @return EnemyBullet
     */
    virtual Objects GetObject() override;

    /**
     * @brief Responsible for the movement mechanics of all generated Enemy bullets
     *
     * Converts radian movement angle to degrees
     * Moves the Enemy bullet by the same method employed in the Enemy class
     * Checks whether or not the bullet is still on-screen for potential deletion
     */
    virtual void Move() override;

    /**
      * @brief Returns the boolean IsAlive status of the Enemy bullet based on it's and the Player craft's collision
     * detection
      * @return _IsAlive
      */
    virtual bool Status() override;

    /**
   * @brief Prevents the re-creation of Enemy Bullets after being provided the Alive status of the Enemy Bullet
   * @return false
   */
    virtual bool Respawns() override;

    /**
     * @brief Sets the boolean IsAlive status of the Enemy Bullet to false
     */
    virtual void Kill() override;

    /**
     * @brief Returns Collision Radius of the Enemy craft for collision querying
     * @return _CollisionRadius
     */
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _enemyBulletPos;
    bool _IsAlive;
    Screen _screen;
    float _DistToPlayer;
    float _EnemyBulletSpeed = 0.00001;
    float _CollisionRadius = 32;
};

#endif
