#ifndef SHOOTINGOBJECTS_H
#define SHOOTINGOBJECTS_H

#include "MovingObjects.h"
#include <cmath>
#include <memory>
using std::shared_ptr;

const float PI = M_PI;
const float ANGLE_OFFSET = M_PI_2;

/**
 * @class ShootingObjects
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file ShootingObjects.h
 * @brief ShootingObjects class
 *
 * Responsible for proivding the shooting functionality of all classes makaing use of Bullets
 * These include Player, PlayerBullet, Enemy, EnenemyBullet and Satellites
 * Inherits from MoveingObjects
 */

class ShootingObjects : public MovingObjects
{
public:
    /**
     * @brief Recieves the positional location of the called upon object
     * @return position
     */
    virtual ObjectsPosition GetPosition() = 0;

    /**
     * @brief Recieves the called upon object
     * @return Object
     */
    virtual Objects GetObject() = 0;

    /**
     * @brief Allows Object specific movement
     */
    virtual void Move() = 0;

    /**
     * @brief Allows the Object to set its boolean IsAlive status during collision detection
     * @return _IsAlive
     */
    virtual bool Status() = 0;

    /**
     * @brief Provides the called object the ability to make use object specific bullet movement
     * @return true or false
     */
    virtual shared_ptr<MovingObjects> Shoot() = 0;

    /**
     * @brief Provides the Object the ability to respawn in its set initial position
     * @return
     */
    virtual bool Respawns() = 0;

    /**
     * @brief Sets the boolean IsAlive status of the called upon object
     */
    virtual void Kill() = 0;

    /**
     * @brief Returns object specific collision radius used during collision detection
     * @return
     */
    virtual float GetCollisionRadius() = 0;
};

#endif