#include "GameLogic.h"

GameLogic::GameLogic()
    : _presentation()
    , _IsPlaying(true)
    , NASASpawn(false)
    , DestroyerSpawn(false)
    , LaserSpawn(false)
{
    srand(time(0));
    PlayerShip = make_shared<Player>(_screen, Lives);
    _gameObjects.push_back(PlayerShip);
    for(int i = 1; i <= Lives; i++) {
	_Lives = make_shared<PlayerLives>(_screen, i);
	_gameObjects.push_back(_Lives);
    }
}

void GameLogic::Run()
{
    drawSplashScreen();
    drawControlScreen();

    Timer timer;
    timer.Start();
    auto Update_Time = 0.f;
    // 60 Frames per Second
    auto Frame_Time = 1.0f / 6000.f;

    while(_IsPlaying) {
	Update_Time += timer.getDuration();
	timer.Start();

	while(Update_Time > Frame_Time) {
	    EnemySpawn();
	    SatelliteSpawn();
	    AsteroidSpawn();
	    LasersSpawn();
	    UserInputs();
	    PlayerUpdate();
	    BulletsSpawn();
	    CheckForUpgrade();
	    ObjectUpdate();
	    renderObjects();
	    CheckCollisions();

	    Update_Time -= Frame_Time;

	    if(PlayerShip->GameOver() || EnemiesKilled == 10) {
		_IsPlaying = false;
		_presentation.displayGameOverScreen();
		Restart();
	    }
	}
    }
}

void GameLogic::drawSplashScreen()
{
    _presentation.displaySplashScreen();
}

void GameLogic::drawControlScreen()
{
    _presentation.displayControlScreen();
}

// Check For user inputs
void GameLogic::UserInputs()
{
    _presentation.UserInputs();
}

void GameLogic::CheckCollisions()
{
    _collisionHandler.CheckForCollisions(_gameObjects);
}

// Update Player position and shooting accordingly
void GameLogic::PlayerUpdate()
{

    if(_presentation.SpacePressed && Shots == 0) {
	if(PlayerShip->CheckUpgrade()) {
	    _gameObjects.push_back(PlayerShip->Shoot());
	    _gameObjects.push_back(PlayerShip->Shoot());
	} else {
	    _gameObjects.push_back(PlayerShip->Shoot());
	}
	Shots++;
    }
    if(_presentation.LeftKeyPressed)
	PlayerShip->setDirection(PlayerDirection::Clockwise);
    else if(_presentation.RightKeyPressed)
	PlayerShip->setDirection(PlayerDirection::Anticlockwise);
    else
	PlayerShip->setDirection(PlayerDirection::Hold);
    if(!_presentation.SpacePressed && Shots > 0)
	Shots = 0;
}

void GameLogic::renderObjects()
{
    // Display all Objects which are alive
    _presentation.renderWindow(_gameObjects);

    // Remove dead objects from vector using lamda function to return true to the remove function if its status is dead
    _gameObjects.erase(remove_if(_gameObjects.begin(), _gameObjects.end(),
                           [](shared_ptr<MovingObjects>& ObjectsInGame) { return (!ObjectsInGame->Status()); }),
        _gameObjects.end());
}

void GameLogic::ObjectUpdate()
{

    // Update Objects positions and move objects accordingly
    for(auto& gameObject : _gameObjects) {

	// Keep track of number of satellites killed for upgrade
	if(gameObject->GetObject() == Objects::Satellites) {
	    if(!gameObject->Status()) {
		NumOfSats--;
	    }
	}

	// Keep track of number of enemies killed for game over
	if(gameObject->GetObject() == Objects::Enemy) {
	    if(!gameObject->Status()) {
		EnemiesKilled++;
	    }
	}
	if(gameObject->Status()) {
	    gameObject->Move();
	}

	// Allow for Enemy to respawn at centre when moved off screen
	if(gameObject->Respawns()) {
	    Alien = make_shared<Enemy>(_screen);
	    _gameObjects.push_back(Alien);
	    _ShootingGameObjects.push_back(Alien);
	    _gameObjects.push_back(Alien->Shoot());
	}
    }
}
void GameLogic::EnemySpawn()
{
    // Spawn factor to delay enemy spawning and if met spawns an enemy
    if(EnemySpawnFactor == 3000 && Enemies < 10) {
	Alien = make_shared<Enemy>(_screen);
	_gameObjects.push_back(Alien);
	_gameObjects.push_back(Alien->Shoot());

	Enemies++;
	EnemySpawnFactor = 0;
    }
    EnemySpawnFactor++;
}

void GameLogic::AsteroidSpawn()
{

    // Random intervals for asteroid Spawn between 0 and 9999
    int randomAsteroidSpawn = rand() % 10000;
    if(randomAsteroidSpawn == 10 && DestroyerSpawn == false) {
	Destroyer = make_shared<Asteroid>(_screen);
	Destroyer->PlayersPos(PlayerShip);
	_gameObjects.push_back(Destroyer);
	DestroyerSpawn = true;
    }

    // Respawn the Asteroid when off screen for next attack
    if(DestroyerSpawn == true) {
	if(!Destroyer->Status()) {
	    DestroyerSpawn = false;
	}
    }
}

void GameLogic::SatelliteSpawn()
{

    // Random spawn interval for satellites to spawn
    int randomSatelliteSpawn = rand() % 10000;
    if(randomSatelliteSpawn == 1 && NASASpawn == false) {
	for(int i = 1; i <= 3; i++) {
	    NASA = make_shared<Satellite>(_screen, i);
	    NASA->PlayersPos(PlayerShip);
	    _gameObjects.push_back(NASA);
	    _ShootingGameObjects.push_back(NASA);
	    _gameObjects.push_back(NASA->Shoot());
	}
	NASASpawn = true;
    }
}

void GameLogic::BulletsSpawn()
{
    // Delay on Bullet firing
    if(BulletSpawnFactor == 1000) {
	// For all objects that shoot shoot
	for(auto& gameObject : _ShootingGameObjects) {

	    if(gameObject->GetObject() == Objects::Satellites && NASASpawn == true) {
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
    // Check for player weapon upgrade if all satellites are killed and player has not died after
    if(NumOfSats == 0) {
	PlayerShip->WeaponUpgrade();
	NumOfSats--;
    } else if((NASASpawn == true) && (PlayerShip->CheckUpgrade() == false) && (NumOfSats == -1)) {
	NASASpawn = false;
	NumOfSats = 3;
    }
}

void GameLogic::LasersSpawn()
{
    // Delay on laser generators spaning
    int randomLaserSpawn = rand() % 10000;
    if(randomLaserSpawn == 10 && LaserSpawn == false) {
	Laser = make_shared<LaserGenerators>(_screen);
	Laser->PlayersPos(PlayerShip);
	_gameObjects.push_back(Laser);
	LaserSpawn = true;
    }
}

// Reset all variables for Restart of the game
void GameLogic::Restart()
{
    _IsPlaying = true;

    NASASpawn = false;
    DestroyerSpawn = false;

    _gameObjects.clear();
    _ShootingGameObjects.clear();
    Lives = 4;
    PlayerShip = make_shared<Player>(_screen, Lives);
    _gameObjects.push_back(PlayerShip);
    for(int i = 1; i <= Lives - 1; i++) {
	_Lives = make_shared<PlayerLives>(_screen, i);
	_gameObjects.push_back(_Lives);
    }
    PlayerShip->Kill();
    PlayerShip->setDirection(PlayerDirection::Hold);
    EnemiesKilled = 0;
    Enemies = 0;
    Run();
}
