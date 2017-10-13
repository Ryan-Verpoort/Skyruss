#ifndef ASTEROID_H
#define ASTEROID_H

#include "Screen.h"
#include "MovingObjects.h"
#include "Player.h"
#include <cmath>
#include <memory>
using std::shared_ptr;
/**
 * @class Asteroid
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file Asteroid.h
 * @brief Responsible for redering and movement of Asteroid object
 *
 * Handles positional redering and movement of all created Asteroid objects
 * Functions Inherited From MovinObjects Class
*/

class Asteroid : public MovingObjects
{
public:
    /**
     * @brief Default Asteroid constructor
     *
     * Initialises creation of Asteroids
     * Sets the Asteroid position radius
     * Initialises the current x and y positions to the centre of the screen
     * Initialises the initial x and y positions to the centre of the screen
     * @param screen Provides the created object the current resolution size of the display window
     */

    Asteroid(Screen screen);

    /**
     * @brief Returns the current postion of the created Asteroid
     * @return position
     */
    virtual ObjectsPosition GetPosition() override;

    /**
     * @brief Returns an Object of type Asteroid
     * @return Asteroid
     */
    virtual Objects GetObject() override;

    /**
     * @brief Handles movement functionality of created Asteroid
     *
     * Sets the speed at which the Asteroid moves
     * Calculates the distance between the Asteroids current position and the Player's current position at time of call
     * Increments the x and y position such that the Asteroid position moves incrementally closer to the Player's last
     * position
     * Checks whether or not the Asteroid is still on-screen and if not, call the destroy function
     */
    virtual void Move() override;

    /**
     * @brief Returns the current collision status of the Asteroid
     * @return _IsAlive
     */
    virtual bool Status() override;

    /**
     * @brief When called, sets the boolean IsAlive status of the object to false
     */
    virtual void Kill() override;

    /**
     * @brief Sets the respawn status of the Asteroid to false
     * @return false
     */
    virtual bool Respawns() override;

    /**
     * @brief Returns the collision radius of the Asteroid for Player-Asteroid collision handling
     * @return _CollisionRadius
     */
    virtual float GetCollisionRadius() override;

    /**
     * @brief Provides the Player's current postion for potential collision handling
     * @param _player
     */
    void PlayersPos(shared_ptr<Player> _player);

private:
    ObjectsPosition _AsteroidPos;
    ObjectsPosition _PlayerPos;
    bool _IsAlive;
    Screen _screen;
    float _PlayerXPos;
    float _PlayerYPos;
    float _DistToPlayer;
    float _CollisionRadius = 64;
};

#endif