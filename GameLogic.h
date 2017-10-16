#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Asteroid.h"
#include "CollisionHandler.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "GamePresentation.h"
#include "LaserGenerators.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "PlayerLives.h"
#include "Satellite.h"
#include "Timer.h"

#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;

class GameLogic
{
public:
    GameLogic();
    void Run();
    void AsteroidSpawn();
    void EnemySpawn();
    void SatelliteSpawn();
	void LasersSpawn();
    void renderObjects();
    void PlayerUpdate();
    void ObjectUpdate();
    void UserInputs();
    void drawSplashScreen();
    void drawControlScreen();
    void CheckCollisions();
    void BulletsSpawn();
    void CheckForUpgrade();
    void Restart();

private:
    shared_ptr<PlayerBullet> _playerBullet;
    GamePresentation _presentation;
    Screen _screen{ 1000, 750 };
    shared_ptr<Player> PlayerShip;
    shared_ptr<PlayerLives> _Lives;
    shared_ptr<Enemy> Alien;
    shared_ptr<Satellite> NASA;
    shared_ptr<Asteroid> Destroyer;
	shared_ptr<LaserGenerators> Laser;
    shared_ptr<EnemyBullet> _EnemyBullet;
    vector<shared_ptr<MovingObjects> > _gameObjects;
    vector<shared_ptr<ShootingObjects> > _ShootingGameObjects;
    bool _IsPlaying;
    bool _isSplashScreen;
    bool NASASpawn;
    bool DestroyerSpawn;
	bool LaserSpawn;
    int Shots = 0;
    int Enemies = 0;
    int EnemiesKilled = 0;
    int NumOfSats = 3;
    int Lives = 3;
    int EnemySpawnFactor = 3000;
	int LaserSpawnFactor = 0;
    int BulletSpawnFactor = 0;

    CollisionHandler _collisionHandler;
};

#endif