#ifndef ENEMY_H
#define ENEMY_H

#include "ShootingObjects.h"
#include "Screen.h"
#include "EnemyBullet.h"

/**
 * @class Enemy
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file Enemy.h
 * @brief Enemy rendering and movement class
 *
 * Responsible for the positional rendering and movement mechanincs of enemy crafts
 */
class Enemy : public ShootingObjects
{
public:
    /**
    * @brief Default Constructor for the Enemy class
    *
    * Allows for the creation, destruction and rendering of Enemy objects
    * On every Game loop, Enemy class functions are called to query the current position and status of on-screen
    * rendered Enemy objects
    * Used to set the initial x and y positions of each creted Enemy craft, as well as the current x and y positions of
    * each Enemy craft to the centre of the screen
    * Sets the angle at which the created Enemy craft is to move, as well as the craft's radius
    * @param screen
    */
    Enemy(Screen screen);

    /**
     * @brief Returns the current position of Enemy craft
     * @return _enemyPos
     */
    virtual ObjectsPosition GetPosition() override;

    /**
     * @brief Returns Object of type Enemy
     * @return Enemy
     */
    virtual Objects GetObject() override;

    /**
     * @brief Responsible for the movement mechanics of all rendered Enemy crafts
     *
     * Converts radian angle to degrees
     * Sets the current x position of the Enemy craft by taking the cosine of the angle
     * Sets the current y position of the Enemy craft by taking the Sine of the angle
     * Checks the if the Enemy craft has reached the edge of the screen and detroys it if beyond
     */
    virtual void Move() override;

    /**
     * @brief Returns the boolean IsAlive status of the craft
     * @return _IsAlive
     */
    virtual bool Status() override;

    /**
     * @brief Provides the current Enemy craft's position to the EnemyBullet class to allow for shooting
     * @return _enemyPos, _screen
     */
    virtual shared_ptr<MovingObjects> Shoot() override;

    /**
     * @brief Sets the boolean IsAlive status of the Enemy craft to false
     */
    virtual void Kill() override;

    /**
     * @brief Allows for the re-creation of Enemy crafts after being provided the Alive status of the Enemy Craft
     *
     * Responsible for redrwaing the Enemy craft in the centre of the screen after the Enemy craft has been killed, or
     * has ventured off the edges of the screen
     * @return
     */
    virtual bool Respawns() override;

    /**
     * @brief Returns the collision radius of the Enemy craft to be used in collision detection and handling
     * @return _CollisionRadius
     */
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _enemyPos;
    Screen _screen;
    EnemyBullet _enemyBullet;
    float _EnemySpeed = 0.005;
    bool _IsAlive;
    bool _ObjectRespawns;
    float _CollisionRadius = 32;
};

#endif