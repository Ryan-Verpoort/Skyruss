#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerBullet.h"
#include "PlayerDirection.h"
#include "PlayerLives.h"
#include "Screen.h"
#include "ShootingObjects.h"

/**
 * @class Player
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file Player.h
 * @brief PLayer generation and movement class
 *
 * Responsible for the positional rendering and generatiln of the Player craft.
 * Responsible for cirvular movement of the Player craft
 * Responsible for providing positional information at call as well as the Alive status of the on-screen player craft
 */
class Player : public ShootingObjects
{

public:
    /**
     * @brief Default Player Constructor
     *
     * Allows for the creation of Player craft objects to be used during run time
     * Through each game loop, relevant functions are used to provide and set the positional location of the Player
     * craft, as well as the current Alive status of the Player object
     * Additionally functional atributes of the Player craft are set to be provided during collision queries
     * @param screen
     * @param NumberOfLives
     */
    Player(Screen screen, int NumberOfLives);

    /**
     * @brief Returns the current movement Direction of the Player craft
     * @return _Direction
     */
    PlayerDirection GetDirection();

    /**
     * @brief Returns the current Player craft postion
     * @return _PlayerPosition
     */
    virtual ObjectsPosition GetPosition() override;

    /**
     * @brief Returns an object of type Player
     * @return Player
     */
    virtual Objects GetObject() override;

    /**
     * @brief Allows for the circular movement of the Player craft basesd on user keyboard input
     *
     * From infromation prvided by the GetDirection function, Move makes use of angle increments to move the Pplayer
     * craft in the direction provided from the polled key press along the specidifed arc
     * Move makes use of GetDirection, PlayerPoistion as well as GetRadius
     * Converts the radian angle to degrees
     * Moves the x-position of the Player craft by taking the Cosine of the angle
     * Moves the y-position of the Player craft by taking the Sine of the angle
     */
    virtual void Move() override;

    /**
     * @brief Provides the Alive status of the Player craft based on information returned from Collision detection
     * @return _IsAlive
     */
    virtual bool Status() override;

    /**
     * @brief Provides the Player craft with the ability to shoot Player Bullets toward Enemy craft
     *
     * Bullets are created at the current location of the Player object
     * The amount of bullets created are deoendent in whether or not the weapon upgrade returns true
     * The Player's position is passed into the PlayerBullet class
     * @return
     */
    virtual shared_ptr<MovingObjects> Shoot() override;

    /**
     * @brief Falsefies the Respawn status of the Player object
     * @return false
     */
    virtual bool Respawns() override;

    /**
     * @brief When called, it sets the Alive status of the Player object to false and resets the PLayer position to the
     * center of the screen
     */
    virtual void Kill() override;

    /**
     * @brief Returns the collision radius of the Player object
     * @return _CollisionRadius
     */
    virtual float GetCollisionRadius() override;

    /**
     * @brief Sets the movement direction as specified by the user input
     * @param direction
     */
    void setDirection(PlayerDirection direction);

    /**
     * @brief Resets the player position and decreases Player lives after collision with anouther object
     *
     * Decreases the number of lives of the Player craft
     * Sets the Alive status to true
     * Sets the weapon upgrade status to false
     */
    void ResetPlayer();

    /**
     * @brief Checks the number of lives of the Player to determine whether or not the game is over
     * @return true if _NumberOfLives < 0
     * @return false if _NumberOfLives < 0
     */
    bool GameOver();

    /**
     * @brief Sets WeaponUprgade to true when called
     */
    void WeaponUpgrade();

    /**
     * @brief Checks the status of the WeaponUpgrade when called
     * @return _upgrade
     */
    bool CheckUpgrade();

private:
    ObjectsPosition _PlayerPosition;
    PlayerDirection _Direction;
    Screen _screen;
    int _NumberOfLives;
    PlayerBullet _PlayersBullet;
    bool _IsAlive;
    float _PlayerSpeed = 0.25;
    float _CollisionRadius = 64;
    int _bullets = 0;
    bool _upgrade;
};

#endif
