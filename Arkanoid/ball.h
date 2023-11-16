///ball.h
/**
 * Plik naglowkowy w ktorym sa zawarte klasy oraz wywolanie funkcji dotyczacych implementacji pileczki
*/
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
/// Ball
/**
 * Implementacja klasy z odwolaniem do klasy skladowej jezyka sfml ktora zawiera
 * Funkcja tworzaca konstruktor z dwoma parameatrami
 * Funkcja usuwajaca dowolny konstruktor
 * Funkcja dodjaca dowolny destruktor
 * Funkcja aktualizujaca polozenie pileczki
 * Funkcja wektorowa
 * Utworzenie okregu funkcji sfml
 * Implementacja promienia pileczki
 * Implementacja predkosci pileczki
 * Funkcja wektorowa ustalajaca szybkosc pileczki na planszy
 *
*/
class Ball : public Drawable
{
public:
	Ball(float t_X, float t_Y);
	Ball() = delete;
	~Ball() = default;

	void update();
	void moveUp();
	void moveUpLeft();
	void moveUpRight();
	void moveDown();
	void moveDownLeft();
	void moveDownRight();
	void moveRight();
	void moveLeft();

	Vector2f getPosition();  ///funkja wektoroawoa 

	float left();
	float right();
	float top();
	float bottom();

private:
	CircleShape shape;
	const float ballRadius{ 10.0f };
	float ballVelocity{ 5.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};