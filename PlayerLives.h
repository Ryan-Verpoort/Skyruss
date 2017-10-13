#ifndef PLAYERLIVES_H
#define PLAYERLIVES_H

#include "MovingObjects.h"
#include "Screen.h"

/**
 * @class PlayerLives
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file PlayerLives.h
 * @brief Responsible for storing and displaying the number of lives the Player craft has
 */
class PlayerLives : public MovingObjects
{
public:
    /**
     * @brief PlayerLives Contructor
     *
     * Allows for the creation of PlayerLives objects to be displayed in the top left corner of the screen
     * Functions allow for the incrementing and decrementing of lives based on PLayer objects collision detection
     * @param screen
     * @param NumberOfLives
     */
    PlayerLives(Screen screen, int NumberOfLives);

    /**
     * @brief Returns the positional location of the PlayerLives
     * @return _LivesPos
     */
    virtual ObjectsPosition GetPosition() override;

    /**
     * @brief Returns object of type Life
     * @return Life
     */
    virtual Objects GetObject() override;

    /**
     * @brief Displayed lives remain in a fixed postion, but move function must be overridden as it is inherited from
     * the MovingObjects class
     */
    virtual void Move() override;

    /**
     * @brief Returns the Alive status of the Lives Object
     * @return _IsAlive
     */
    virtual bool Status() override;

    /**
     * @brief Sets the Alive status of Lives to false when called
     */
    virtual void Kill() override;

    /**
     * @brief Lives fdo not Respawn. As such Kill Respawn returns false for Lives object
     * @return false
     */
    virtual bool Respawns() override;

    /**
     * @brief Does not collide with other objects, as such false is returned.
     *
     * Must be overridden as it is inherited from the CollisionHandler class
     * @return
     */
    virtual float GetCollisionRadius() override;

private:
    ObjectsPosition _LivesPos;
    Screen _screen;
    bool _IsAlive;
    float _CollisionRadius = 32;
};
#endif