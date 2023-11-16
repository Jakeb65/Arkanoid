///ball.cpp
/**
* Plik zawierajacy kod implementujacy pileczke
* "#include "ball.h"" plik nagolowkowy
*/

#include "ball.h"

///Ball
/**
* Konstruktor z dwoma parametrami
*
*/

Ball::Ball(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::Color(252, 52, 198));
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

///draw
/**
* Funkcja rysujaca pileczke
* Funkcja definiuje metode
*/

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

///Update
/**
* Funkcja aktualizuaca polozenie pileczki wzgledem osi "x" oraz "y"
* Funkcja analizuje polozenie pileczki poprzez sprawdzenie gdzie znajduje sie jej srodek na planszy
* Funkcja "else if" kontroluje rozgalezienie warunkowe
*/
int a = 0;
void Ball::update()
{
	shape.move(this->velocity);

	if (this->left() < 0)
	{
		velocity.x = ballVelocity + 1;
	}
	else if (this->right() > 800)
	{
		velocity.x = -ballVelocity - 1;
	}
	else if (this->top() < 0)
	{
		velocity.y = ballVelocity + 1;
	}
	else if (this->bottom() > 600)
	{
		//velocity.y = -ballVelocity - 1;
	}
}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

///moveDown
/**
* Funkcja pozwalajaca na porusznie sie w dol
*/

void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}

///moveDownLeft
/**
* Funkcja pozwalajaca na porusznie sie w dolna lewa strone
*/

void Ball::moveDownLeft()
{
	this->velocity.y = ballVelocity;
	this->velocity.x = ballVelocity - 2;
}

///moveDownRight
/**
* Funkcja pozwalajaca na porusznie sie w dolna prawa strone
*/
void Ball::moveDownRight()
{
	this->velocity.y = ballVelocity;
	this->velocity.x = ballVelocity + 2;
}

///moveUp
/**
* Funkcja pozwalajaca na porusznie sie w gore
*/

void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}

///moveUpLeft
/**
* Funkcja pozwalajaca na porusznie sie w gorna lewa strone
*/

void Ball::moveUpLeft()
{
	this->velocity.y = -ballVelocity;
	this->velocity.x = ballVelocity - 2;
}

///moveUpRight 
/**
* Funkcja pozwalajaca na porusznie sie w gorna prawa strone
*/

void Ball::moveUpRight()
{
	this->velocity.y = -ballVelocity;
	this->velocity.x = ballVelocity + 2;
}
///moveRight
/**
* Funkcja pozwalajaca na porusznie sie w prawo
*/
void Ball::moveRight()
{
	this->velocity.x = ballVelocity + 1;
}
///moveLeft
/**
* Funkcja pozwalajaca na porusznie sie w lewo
*/
void Ball::moveLeft()
{
	this->velocity.x = -ballVelocity - 1;
}
///getPosition
/**
* Funkcja wektorowa zwracjaca polozenie pileczki
*/
Vector2f Ball::getPosition()
{
	return shape.getPosition();
}
