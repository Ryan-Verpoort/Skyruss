#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Asteroid.h"
#include "CollisionHandler.h"
#include "GamePresentation.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "PlayerLives.h"
#include "Satellite.h"
#include "State.h"
#include "Timer.h"
#include <vector>
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;

class GameLogic
{
public:
    GameLogic();
    void run();
    void renderObjects();
    void spawnEnemy();
    void updatePlayerPosition();
    void updateEntities();
    void inputCommands();
    void drawSplashScreen();
    void spawnSatellite();
    void collisions();
    void SpawnAsteroid();
    void SpawnBullets();
	bool SatellitesDown();

    int counter = 0;

private:
    shared_ptr<PlayerBullet> _playerBullet;
    GamePresentation _presentation;
    Screen _screen{ 1000, 800 };
    shared_ptr<Player> _player;
    shared_ptr<PlayerLives> _Lives;
    shared_ptr<Enemy> _enemy;
    shared_ptr<Satellite> _satellite;
    shared_ptr<Asteroid> _Asteroid;
    shared_ptr<EnemyBullet> _EnemyBullet;
    vector<shared_ptr<MovingObjects> > _gameObjects;
    vector<shared_ptr<ShootingObjects> > _ShootingGameObjects;
    bool _isRunning;
    State _gameState;
    bool _isSplashScreen;
    bool _satelliteSpawn;
    bool _AsteroidSpawn;
    int Enemies = 0;
    int Lives = 3;
    int spawnFactor = 3000;
    int BulletSpawnFactor = 0;
	bool _Upgrade;

    CollisionHandler _collisionHandler;
};

#endif