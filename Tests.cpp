#include "Asteroid.h"
#include "CollisionHandler.h"
#include "GameLogic.h"
#include "GamePresentation.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "PlayerLives.h"
#include "Satellite.h"
#include "Screen.h"
#include "State.h"
#include "Timer.h"

#include <vector>

using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

Screen _screen(1000, 800);

// sf::RenderWindow window(sf::VideoMode(800, 800), "Gyruss");

TEST_CASE("Moves in Clockwise direction")
{
    // Create player Object
    Player playership(_screen, 3);

    // Check Player starts in correct position bootom of screen in the middle
    CHECK(playership.GetPosition().GetCurrentX() == _screen.getScreenCentreX());
    CHECK(playership.GetPosition().GetCurrentY() == (_screen.getScreenCentreY() + _screen.getObjectRadius()));

    // Set Direction to Clockwise and move twice
    playership.setDirection(PlayerDirection::Clockwise);
    playership.Move();
    playership.Move();

    // Check Player No Longer is at starting position
    CHECK_FALSE(playership.GetPosition().GetCurrentX() == _screen.getScreenCentreX());
    CHECK_FALSE(playership.GetPosition().GetCurrentY() == (_screen.getScreenCentreY() + _screen.getObjectRadius()));

    // Check Player mover correct Direction
    CHECK(playership.GetPosition().GetCurrentX() == 498.4292f);
    CHECK(playership.GetPosition().GetCurrentY() == 759.99658f);
}

TEST_CASE("Moves in Anti Clockwise direction")
{
    // Create player Object
    Player playership(_screen, 3);

    // Check Player starts in correct position bootom of screen in the middle
    CHECK(playership.GetPosition().GetCurrentX() == _screen.getScreenCentreX());
    CHECK(playership.GetPosition().GetCurrentY() == (_screen.getScreenCentreY() + _screen.getObjectRadius()));

    // Set Direction to Anti-Clockwise and move twice
    playership.setDirection(PlayerDirection::Anticlockwise);
    playership.Move();
    playership.Move();

    // Check Player No Longer is at starting position
    CHECK_FALSE(playership.GetPosition().GetCurrentX() == _screen.getScreenCentreX());
    CHECK_FALSE(playership.GetPosition().GetCurrentY() == (_screen.getScreenCentreY() + _screen.getObjectRadius()));

    // Check Player mover correct Direction
    CHECK(playership.GetPosition().GetCurrentX() == 501.57077f);
    CHECK(playership.GetPosition().GetCurrentY() == 759.99658f);
}

TEST_CASE("Enemy ship spawn's at center")
{
    // Create Enemy Object
    Enemy enemy(_screen);

    // Check Enemy Spawns in Centre of the Screen
    CHECK(_screen.getScreenCentreX() == enemy.GetPosition().GetCurrentX());
    CHECK(_screen.getScreenCentreY() == enemy.GetPosition().GetCurrentY());
}

TEST_CASE("Asteroid spawn's at center")
{
    // Create Asteroid Object
    Asteroid Destroyer(_screen);

    // Check Enemy Spawns in Centre of the Screen
    CHECK(_screen.getScreenCentreX() == Destroyer.GetPosition().GetCurrentX());
    CHECK(_screen.getScreenCentreY() == Destroyer.GetPosition().GetCurrentY());
}

TEST_CASE("EnemyShip moves away from centre")
{
    // Create Enemy Object
    Enemy enemy(_screen);

    // Move Enemy Twice
    enemy.Move();
    enemy.Move();

    // Check Enemy Moves form Centre of the Screen
    CHECK_FALSE(enemy.GetPosition().GetCurrentX() == _screen.getScreenCentreX());
    CHECK_FALSE(enemy.GetPosition().GetCurrentY() == _screen.getScreenCentreY());

    // Check Enemy moves on screen
    CHECK(enemy.GetPosition().GetCurrentX() == 501.10721f);
    CHECK(enemy.GetPosition().GetCurrentY() == 401.64148f);
}

TEST_CASE("Asteroid moves away from centre")
{
    // Create Asteroid Object
    Asteroid Destroyer(_screen);

    // Move Asteroid twice
    Destroyer.Move();
    Destroyer.Move();

    // Check Enemy Moves form Centre of the Screen
    CHECK_FALSE(_screen.getScreenCentreX() == Destroyer.GetPosition().GetCurrentX());
    CHECK_FALSE(_screen.getScreenCentreY() == Destroyer.GetPosition().GetCurrentY());

    // Check Asteroid moves on screen
    CHECK(Destroyer.GetPosition().GetCurrentX() == 499.21912f);
    CHECK(Destroyer.GetPosition().GetCurrentY() == 399.37531f);
}

TEST_CASE("EnemyShip Dies If Off Screen")
{
    // Create Enemy Object
    Enemy enemy(_screen);

    // Check if enemy is alive
    CHECK(enemy.Status());

    // Move Untill Status changes
    while(enemy.Status()) {
	enemy.Move();
    }

    // Check if Status has changed
    CHECK_FALSE(enemy.Status());
}

TEST_CASE("Asteroid Dies If Off Screen")
{
    // Create Asteroid Object
    Asteroid Destroyer(_screen);

    // Check if Asteroid is alive
    CHECK(Destroyer.Status());

    // Move Untill Status changes
    while(Destroyer.Status()) {
	Destroyer.Move();
    }

    // Check if Status has changed
    CHECK_FALSE(Destroyer.Status());
}

TEST_CASE("Satellite spawn's in front of Player")
{
    // Player Objects
    shared_ptr<Player> PlayerShip;
    PlayerShip = make_shared<Player>(_screen, 3);

    // Satellite Objects
    shared_ptr<Satellite> NASA1;
    shared_ptr<Satellite> NASA2;
    shared_ptr<Satellite> NASA3;
    NASA1 = make_shared<Satellite>(_screen, 1);
    NASA2 = make_shared<Satellite>(_screen, 2);
    NASA3 = make_shared<Satellite>(_screen, 3);
    NASA1->PlayersPos(PlayerShip);
    NASA2->PlayersPos(PlayerShip);
    NASA3->PlayersPos(PlayerShip);

    NASA1->Move();
    NASA2->Move();
    NASA3->Move();
    NASA1->Move();
    NASA2->Move();
    NASA3->Move();

    // Check Satellites are in different X positions
    CHECK_FALSE(NASA1->GetPosition().GetCurrentX() == NASA2->GetPosition().GetCurrentX());
    CHECK_FALSE(NASA1->GetPosition().GetCurrentX() == NASA3->GetPosition().GetCurrentX());
    CHECK_FALSE(NASA2->GetPosition().GetCurrentX() == NASA3->GetPosition().GetCurrentX());

    // Check Satellites are in different Y positions
    CHECK_FALSE(NASA1->GetPosition().GetCurrentY() == NASA2->GetPosition().GetCurrentY());
    CHECK_FALSE(NASA1->GetPosition().GetCurrentY() == NASA3->GetPosition().GetCurrentY());
    CHECK_FALSE(NASA2->GetPosition().GetCurrentY() == NASA3->GetPosition().GetCurrentY());
}

TEST_CASE("Satellite moves")
{
    // Player Objects
    shared_ptr<Player> PlayerShip;
    PlayerShip = make_shared<Player>(_screen, 3);

    // Create Satellite Objects
    shared_ptr<Satellite> NASA1;
    shared_ptr<Satellite> NASA2;
    shared_ptr<Satellite> NASA3;
    NASA1 = make_shared<Satellite>(_screen, 1);
    NASA2 = make_shared<Satellite>(_screen, 2);
    NASA3 = make_shared<Satellite>(_screen, 3);
    NASA1->PlayersPos(PlayerShip);
    NASA2->PlayersPos(PlayerShip);
    NASA3->PlayersPos(PlayerShip);

    CHECK_FALSE(NASA1->GetPosition().GetCurrentX() == 449.0f);
    CHECK_FALSE(NASA2->GetPosition().GetCurrentX() == 379.0f);
    CHECK_FALSE(NASA3->GetPosition().GetCurrentX() == 367.0f);

    // Check Y Position
    CHECK_FALSE(NASA1->GetPosition().GetCurrentY() == 660.1f);
    CHECK_FALSE(NASA2->GetPosition().GetCurrentY() == 705.0f);
    CHECK_FALSE(NASA3->GetPosition().GetCurrentY() == 622.0f);

    // Move Each Satellite
    NASA1->Move();
    NASA2->Move();
    NASA3->Move();

    // Check X Position
    CHECK(NASA1->GetPosition().GetCurrentX() == 450.0f);
    CHECK(NASA2->GetPosition().GetCurrentX() == 379.18127f);
    CHECK(NASA3->GetPosition().GetCurrentX() == 367.32727f);

    // Check Y Position
    CHECK(NASA1->GetPosition().GetCurrentY() == 660.01251f);
    CHECK(NASA2->GetPosition().GetCurrentY() == 705.45966f);
    CHECK(NASA3->GetPosition().GetCurrentY() == 622.15173f);
}

TEST_CASE("Player Bullet Spawn at Player Position")
{
    // Create Player Objects
    Player PlayerShip(_screen, 3);
    ObjectsPosition PlayersPos;

    // Move Player
    PlayerShip.setDirection(PlayerDirection::Anticlockwise);
    PlayerShip.Move();
    PlayerShip.Move();

    // Give Players New Co-Ordinates to player bullet
    PlayersPos = PlayerShip.GetPosition();
    PlayerBullet _playerbullet(PlayersPos, _screen);

    // Check Bullet Spawns at Enemy location
    CHECK(_playerbullet.GetPosition().GetCurrentX() == PlayerShip.GetPosition().GetCurrentX());
    CHECK(_playerbullet.GetPosition().GetCurrentY() == PlayerShip.GetPosition().GetCurrentY());
}

TEST_CASE("Bullet Reaches Centre of Screen and is destroyed")
{
    // Create Player Objects
    Player PlayerShip(_screen, 3);
    ObjectsPosition PlayersPos;

    // Give Players Co-Ordinates to player bullet
    PlayersPos = PlayerShip.GetPosition();
    PlayerBullet _playerbullet(PlayersPos, _screen);

    CHECK_FALSE(_playerbullet.GetPosition().GetCurrentY() == 404.68381f);

    // Check Bullet is Alive
    CHECK(_playerbullet.Status());

    while(_playerbullet.Status()) {
	_playerbullet.Move();
    }
    // Check Status has changed
    CHECK_FALSE(_playerbullet.Status());

    // Check Last co-ordinates
    CHECK(_playerbullet.GetPosition().GetCurrentX() == _screen.getScreenCentreX());
    // Y value depends on Players position and _bullets x position
    CHECK(_playerbullet.GetPosition().GetCurrentY() == 404.68381f);
}

TEST_CASE("Enemy Bullet Spawns at enemy Spawning Co-ordinates")
{
    // Create Enemy Objects
    Enemy Alien(_screen);
    ObjectsPosition AlienPos;

    // Give Enemys positin to enemy bullet
    AlienPos = Alien.GetPosition();
    EnemyBullet _enemybullet(AlienPos, _screen);

    // Check Bullet Spawns by Enemy
    CHECK(_enemybullet.GetPosition().GetCurrentX() == Alien.GetPosition().GetCurrentX());
    CHECK(_enemybullet.GetPosition().GetCurrentY() == Alien.GetPosition().GetCurrentY());
}

TEST_CASE("Enemy Bullet Spawns at enemy Current Co-ordinates")
{
    // Create Enemy Objects
    Enemy Alien(_screen);
    ObjectsPosition AlienPos;

    // Move Enemy
    Alien.Move();
    Alien.Move();

    // Give New Co-Ordinates
    AlienPos = Alien.GetPosition();
    EnemyBullet _enemybullet(AlienPos, _screen);

    // Check Bullet Spawns at Enemy location
    CHECK(_enemybullet.GetPosition().GetCurrentX() == Alien.GetPosition().GetCurrentX());
    CHECK(_enemybullet.GetPosition().GetCurrentY() == Alien.GetPosition().GetCurrentY());
}

TEST_CASE("Enemy Bullet Reaches Edge of Screen and is destroyed")
{
    // Create Player Objects
    Enemy Alien(_screen);
    ObjectsPosition AlienPos;

    // Give Players Co-Ordinates to player bullet
    AlienPos = Alien.GetPosition();
    EnemyBullet _enemybullet(AlienPos, _screen);

    // Check Bullet is Alive
    CHECK(_enemybullet.Status());

    while(_enemybullet.Status()) {
	_enemybullet.Move();
    }
    // Check Status has changed
    CHECK_FALSE(_enemybullet.Status());

    // Check Y value less than screen edge
    CHECK_FALSE(_enemybullet.GetPosition().GetCurrentX() > 0);
}

TEST_CASE("Player Loose Lifes")
{
    // Create Player Object
    Player Playership(_screen, 3);

    // Check Player is Alive
    CHECK(Playership.Status());

    // Check if game is still running
    CHECK_FALSE(Playership.GameOver());

    // Player Life Lost
    Playership.Kill();

    // One Life Lost still playing
    CHECK_FALSE(Playership.GameOver());

    // Player Life Lost
    Playership.Kill();

    // Two Lifes Lost still playing
    CHECK_FALSE(Playership.GameOver());

    // Player Life Lost
    Playership.Kill();

    // Three Lifes Lost still playing
    CHECK_FALSE(Playership.GameOver());

    // Player Life Lost
    Playership.Kill();

    // All lifes lost game is over
    CHECK(Playership.GameOver());
}

TEST_CASE("Player Bullet Collide WIth Enemy")
{
    shared_ptr<Enemy> Alien;
    shared_ptr<Player> PlayerShip;
    shared_ptr<PlayerBullet> _playerbullet;
    PlayerShip = make_shared<Player>(_screen, 3);
    Alien = make_shared<Enemy>(_screen);
    ObjectsPosition PlayerPos;
    CollisionHandler _collisionHandler;
    PlayerPos = PlayerShip->GetPosition();
    _playerbullet = make_shared<PlayerBullet>(PlayerPos, _screen);

    vector<shared_ptr<MovingObjects> > _gameObjects;
    _gameObjects.push_back(Alien);
    _gameObjects.push_back(_playerbullet);

    // Set Enemy in Path of Bullet
    Alien->GetPosition().SetCurrentX(_screen.getScreenCentreX());
    Alien->GetPosition().SetCurrentY(_screen.getScreenCentreY() + 100);

    // Check Enemy and bullet Alive
    CHECK(Alien->Status());
    CHECK(_playerbullet->Status());

    // Move Bullet untill bullet destroyed
    while(Alien->Status()) {

	_collisionHandler.CheckForCollisions(_gameObjects);
	_playerbullet->Move();
    }

    // Check Enemy and bullet Dead
    CHECK_FALSE(Alien->Status());
    CHECK_FALSE(_playerbullet->Status());
}

TEST_CASE("Player Bullet Collide WIth Satellite")
{
    shared_ptr<Satellite> NASA;
    shared_ptr<Player> PlayerShip;
    shared_ptr<PlayerBullet> _playerbullet;
    PlayerShip = make_shared<Player>(_screen, 3);
    NASA = make_shared<Satellite>(_screen, 1);
    ObjectsPosition PlayerPos;
    CollisionHandler _collisionHandler;
    PlayerPos = PlayerShip->GetPosition();
    _playerbullet = make_shared<PlayerBullet>(PlayerPos, _screen);

    vector<shared_ptr<MovingObjects> > _gameObjects;
    _gameObjects.push_back(NASA);
    _gameObjects.push_back(_playerbullet);

    // Set Satellite in Path of Bullet
    NASA->GetPosition().SetCurrentX(_screen.getScreenCentreX());
    NASA->GetPosition().SetCurrentY(_screen.getScreenCentreY() + 100);

    // Check Satellite and bullet Alive
    CHECK(NASA->Status());
    CHECK(_playerbullet->Status());

    // Move Bullet untill bullet destroyed
    while(NASA->Status()) {
	_collisionHandler.CheckForCollisions(_gameObjects);
	_playerbullet->Move();
    }

    // Check Satellite and bullet Dead
    CHECK_FALSE(NASA->Status());
    CHECK_FALSE(_playerbullet->Status());
}

TEST_CASE("Enemy Bullet Collide WIth Player")
{
    // Create Objects
    shared_ptr<Enemy> Alien;
    shared_ptr<Player> PlayerShip;
    shared_ptr<EnemyBullet> _AlienBullet;
    shared_ptr<PlayerLives> _Lives;
    PlayerShip = make_shared<Player>(_screen, 3);
    Alien = make_shared<Enemy>(_screen);
    _Lives = make_shared<PlayerLives>(_screen, 1);

    // Create two Object Positions
    ObjectsPosition PlayerPos;
    ObjectsPosition AlienPos;

    // Collision Handler
    CollisionHandler _collisionHandler;
    PlayerPos = PlayerShip->GetPosition();
    AlienPos = Alien->GetPosition();

    // Set Angle as Players Angle
    AlienPos.setAngle(PlayerPos.GetAngle());
    _AlienBullet = make_shared<EnemyBullet>(PlayerPos, _screen);

    vector<shared_ptr<MovingObjects> > _gameObjects;

    // Initialise Vector
    _gameObjects.push_back(_Lives);
    _gameObjects.push_back(PlayerShip);
    _gameObjects.push_back(_AlienBullet);

    // Check Live of Player and bullet Alive
    CHECK(_Lives->Status());
    CHECK(_AlienBullet->Status());

    // Move Bullet untill bullet destroyed
    while(_AlienBullet->Status()) {

	_collisionHandler.CheckForCollisions(_gameObjects);
	_AlienBullet->Move();
    }

    // Check PlayerLives and bullet Dead
    CHECK_FALSE(_Lives->Status());
    CHECK_FALSE(_AlienBullet->Status());
}

TEST_CASE("Player Asteroid Collide")
{
    // Create Objects
    shared_ptr<Asteroid> Destroyer;
    shared_ptr<Player> PlayerShip;
    shared_ptr<PlayerLives> _Lives;
    PlayerShip = make_shared<Player>(_screen, 3);
    Destroyer = make_shared<Asteroid>(_screen);
    _Lives = make_shared<PlayerLives>(_screen, 1);

    // Get Players position
    Destroyer->PlayersPos(PlayerShip);

    // Collision Handler
    CollisionHandler _collisionHandler;

    vector<shared_ptr<MovingObjects> > _gameObjects;

    // Populate Vector
    _gameObjects.push_back(_Lives);
    _gameObjects.push_back(PlayerShip);
    _gameObjects.push_back(Destroyer);

    // Check Player live is Alive
    CHECK(_Lives->Status());

    // Move Asteroid untill Live destroyed
    while(_Lives->Status()) {

	_collisionHandler.CheckForCollisions(_gameObjects);
	Destroyer->Move();
    }

    // Check Player Dead
    CHECK_FALSE(_Lives->Status());
}

TEST_CASE("Player Enemy Collide")
{
    // Create Objects
    shared_ptr<Enemy> Alien;
    shared_ptr<Player> PlayerShip;
    shared_ptr<PlayerLives> _Lives;
    PlayerShip = make_shared<Player>(_screen, 3);
    Alien = make_shared<Enemy>(_screen);
    _Lives = make_shared<PlayerLives>(_screen, 1);

    // Create two Object Positions
    ObjectsPosition PlayerPos;
    ObjectsPosition AlienPos;

    // Collision Handler
    CollisionHandler _collisionHandler;
    PlayerPos = PlayerShip->GetPosition();
    AlienPos = Alien->GetPosition();

    AlienPos.setAngle(PlayerPos.GetAngle());

    // Set Angle as Players Angle
    AlienPos.setAngle(PlayerPos.GetAngle());

    vector<shared_ptr<MovingObjects> > _gameObjects;

    // Populate Vector
    _gameObjects.push_back(_Lives);
    _gameObjects.push_back(PlayerShip);
    _gameObjects.push_back(Alien);

    // Check Player live is Alive
    CHECK(_Lives->Status());
    CHECK(Alien->Status());

    // Move Asteroid untill Live destroyed
    while(Alien->Status()) {

	_collisionHandler.CheckForCollisions(_gameObjects);
	Alien->Move();
    }

    // Check Player Dead
    CHECK_FALSE(Alien->Status());
}