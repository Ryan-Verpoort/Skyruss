#include "GameLogic.h"
#include <iostream>

GameLogic::GameLogic()
    : _presentation()
    , _isRunning(true)
    , _gameState(State::Splash)
    , _satelliteSpawn(false)
    , _AsteroidSpawn(false)
{
    srand(time(0));
    _player = make_shared<Player>(_screen);
    _gameObjects.push_back(_player);
    for(int i = 1; i <= Lives; i++) {
	_Lives = make_shared<PlayerLives>(_screen, i);
	_gameObjects.push_back(_Lives);
    }
}

void GameLogic::run()
{
    drawSplashScreen();

    Timer timer;
    timer.Start();
    auto time_since_last_update = 0.f;
    auto time_per_frame = 1.0f / 6000.f;

    while(_isRunning) {
	time_since_last_update += timer.Stop();
	timer.Start();

	while(time_since_last_update > time_per_frame) {
	    inputCommands();
	    SpawnAsteroid();
	    spawnEnemy();
	    spawnSatellite();
	    SpawnBullets();
	    updatePlayerPosition();
	    updateEntities();
	    renderObjects();
	    CheckForUpgrade();
	    _collisionHandler.CheckForCollisions(_gameObjects);
	    time_since_last_update -= time_per_frame;

	    if(_player->isGameOver()) {
		_isRunning = false;
		_presentation.displayGameOverScreen();
	    }
	}
    }
}

void GameLogic::inputCommands()
{
    _presentation.processInputEvents();
}

void GameLogic::updatePlayerPosition()
{

    if(_presentation._isSpacePressed && counter == 0) {
	if(_player->CheckUpgrade()) {
	    _gameObjects.push_back(_player->Shoot());
	    _gameObjects.push_back(_player->Shoot());
	} else {
	    _gameObjects.push_back(_player->Shoot());
	}
	counter++;
    }
    if(_presentation._isLeftPressed)
	_player->setDirection(PlayerDirection::Clockwise);
    else if(_presentation._isRightPressed)
	_player->setDirection(PlayerDirection::Anticlockwise);
    else
	_player->setDirection(PlayerDirection::Hold);
    if(!_presentation._isSpacePressed && counter > 0)
	counter = 0;
}

void GameLogic::renderObjects()
{

    _presentation.renderWindow(_gameObjects);

    _gameObjects.erase(remove_if(_gameObjects.begin(), _gameObjects.end(), [](shared_ptr<MovingObjects>& me) {
	                   return (!me->Status());
	               }), _gameObjects.end());
}

void GameLogic::updateEntities()
{
    for(auto& gameObject : _gameObjects) {

	if(gameObject->GetObject() == Objects::Satellites) {
	    if(!gameObject->Status()) {
		NumOfSats--;
		std::cout << NumOfSats << std::endl;
	    }
	}
	if(gameObject->Status()) {
	    gameObject->Move();
	}
	if(gameObject->Respawns()) {
	    _enemy = make_shared<Enemy>(_screen);
	    _gameObjects.push_back(_enemy);
	    _ShootingGameObjects.push_back(_enemy);
	    _gameObjects.push_back(_enemy->Shoot());
	}
    }
}

void GameLogic::spawnEnemy()
{
    if(spawnFactor == 3000 && Enemies < 10) {
	_enemy = make_shared<Enemy>(_screen);
	_gameObjects.push_back(_enemy);
	_gameObjects.push_back(_enemy->Shoot());

	Enemies++;
	spawnFactor = 0;
    }
    spawnFactor++;
}

void GameLogic::SpawnAsteroid()
{
    int randomSpawnFactor = rand() % 10000;
    if(randomSpawnFactor == 10 && _AsteroidSpawn == false) {
	_Asteroid = make_shared<Asteroid>(_screen);
	_Asteroid->PlayersPos(_player);
	_gameObjects.push_back(_Asteroid);
	_AsteroidSpawn = true;
    }

    if(_AsteroidSpawn == true) {
	if(!_Asteroid->Status()) {
	    _AsteroidSpawn = false;
	}
    }
}

void GameLogic::drawSplashScreen()
{
    _presentation.displaySplashScreen();
}

void GameLogic::spawnSatellite()
{
    int randomSpawnFactor = rand() % 10000;
    if(randomSpawnFactor == 1 && _satelliteSpawn == false) {
	for(int i = 1; i <= 3; i++) {
	    _satellite = make_shared<Satellite>(_screen, i);
	    _satellite->PlayersPos(_player);
	    _gameObjects.push_back(_satellite);
	    _ShootingGameObjects.push_back(_satellite);
	    _gameObjects.push_back(_satellite->Shoot());
	}
	_satelliteSpawn = true;
    }
}

void GameLogic::SpawnBullets()
{
    if(BulletSpawnFactor == 1000) {
	for(auto& gameObject : _ShootingGameObjects) {

	    if(gameObject->GetObject() == Objects::Satellites && _satelliteSpawn == true) {
		if(gameObject->Status()) {
		    _gameObjects.push_back(gameObject->Shoot());
		}
	    }
	    if(gameObject->GetObject() == Objects::Enemy) {
		if(gameObject->Status()) {
		    _gameObjects.push_back(gameObject->Shoot());
		}
	    }
	}
	BulletSpawnFactor = 0;
    }
    BulletSpawnFactor++;
}

void GameLogic::CheckForUpgrade()
{
    if(NumOfSats == 0) {
	_player->WeaponUpgrade();
	NumOfSats--;
    } else if((_satelliteSpawn == true) && (_player->CheckUpgrade() == false) && (NumOfSats == -1)) {
	_satelliteSpawn = false;
	NumOfSats = 3;
    }
}