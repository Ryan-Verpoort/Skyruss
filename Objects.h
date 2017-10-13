#ifndef OBJECTS_H
#define OBJECTS_H

/**
 * @class Objects Enum class
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file EnemyBullet.h
 * @brief Enum class of type Objects
 *
 * Responsible for soring of all objects to be used during run-time
 *
 * @param Player
 * @param Enemy
 * @param Satellites
 * @param Asteroid
 * @param PlayerBullet
 * @param EnemyBullet
 * @param Life
 */
enum class Objects { Player = 0, Enemy, Satellites, Asteroid, PlayerBullet, EnemyBullet, Life };

#endif