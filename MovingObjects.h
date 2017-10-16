#ifndef MOVINGOBJECTS_H
#define MOVINGOBJECTS_H

#include "Objects.h"
#include "ObjectsPosition.h"

/**
 * @class MovingObjects
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file MovingObjects.h
 * @brief MovingObjects class
 *
 * Inherited by all objects making use of movement functionality to assign and record initial and current positions of
 * all moving objects
 */

class MovingObjects
{
public:
    /**
     * @brief Returns the current position of movement object
     * @return position
     */
    virtual ObjectsPosition GetPosition() = 0;

    /**
* @brief Returns object of type specific
* @return object
*/
    virtual Objects GetObject() = 0;

    /**
* @brief Allows for all object specific movement functionality
*/
    virtual void Move() = 0;

    /**
* @brief Provides the boolean IsAlive status of the object based on collision detection and on-screen position
* @return _IsAlive
*/
    virtual bool Status() = 0;

    /**
* @brief Sets the IsAlive status of specific object
*/
    virtual void Kill() = 0;

    /**
* @brief Allows for the respawning or non-respawning of each rendered object
* @return true or false
*/
    virtual bool Respawns() = 0;

    /**
* @brief Returns the collision radius of specified objects to be used during collision detection
* @return _collisionRadius
*/
    virtual float GetCollisionRadius() = 0;
};

#endif