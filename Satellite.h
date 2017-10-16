#ifndef SATELLITE_H
#define SATELLITE_H

#include "Screen.h"
#include "ShootingObjects.h"
#include "EnemyBullet.h"
#include "Player.h"

#include <memory>
using std::shared_ptr;

/**
 * @class Satellite
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file Satellite.h
 * @brief Satellite Class
 *
 * Responsible for the locational rendering and movement of 3 satellite objects in front of the Player craft
 * Responsible for setting the angle between all three satellite objects during initial spawn
 */
class Satellite : public ShootingObjects
{
public:
    /**
     * @brief Satellite class Constructor
     *
     * Reletive functions allow for the generation and movement of the three satellite objects created
     * Provided functionality includes being able to shoot toward the Player and respawn randomly infront of the Player
     *craft
     * @param screen
     * @param NumberOfSats
     */
    Satellite(Screen screen, int NumberOfSats);

    /**
     * @brief Returns the Position of each Satellite object
     * @return _satellitePos
     */
    virtual ObjectsPosition GetPosition() override;

    /**
     * @brief Returns an object of type Satellite
     * @return Satellites
     */
    virtual Objects GetObject() override;

    /**
     * @brief Returns the boolean IsAlive state of each of the three created Satellite objects
     * @return _IsAlive
     */
    virtual bool Status() override;

    /**
     * @brief Sets the postional co-ordinates of the Satellite objects so that they can be used to move around the
     * circumfrance of thier repective circles
     */
    virtual void Move() override;

    /**
     * @brief Sets the Satellite Bullets to appear at the position of the created satellite
     *
     * Gets provided the current Player craft angle such that the bullets can be fired toward the Player's last knon
     * position
     * @return _SatelliteBullet, _screen
     */
    virtual shared_ptr<MovingObjects> Shoot();

    /**
     * @brief When funtion is called it sets the Respawn attribute of the Object to false to ensure that satellites do
     * not
     * respawn immidiatly after being killed
     * @return false
     */
    virtual bool Respawns() override;

    /**
     * @brief Sets the IsAlive status of the object to false when function called from collision handling
     */
    virtual void Kill() override;

    /**
     * @brief Returns the collision radius of each Satellite object to be used during collision detection and handling
     * @return _CollisionRadius
     */
    virtual float GetCollisionRadius() override;

    /**
     * @brief Sets the postion of the three satellite objects to be infront of the Player's current position at time of
     * function call
     *
     * Responsible for checkin which quarant of the screen the Player craft is in so that the Satellite objects can be
     * created with a small positional offset from the current location of the Player craft
     * Also responsible for getting the current movement angle of the Player object so that bullets can be fired toward
     * the Player craft
     * @param _player
     */
    void PlayersPos(shared_ptr<Player> _player);

private:
    ObjectsPosition _satellitePos;
    ObjectsPosition _SatelliteBullet;
    Screen _screen;
    EnemyBullet _enemyBullet;
    float _SatelliteSpeed = 0.00025;
    bool _IsAlive;
    float _CollisionRadius = 64;
    float _PlayerAngle;
    float _PlayerXPos;
    float _PlayerYPos;
};
#endif