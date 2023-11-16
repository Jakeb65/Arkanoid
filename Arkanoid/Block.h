///Block.h
/**
* Plik nagowkowy zawierajcy klase
*/
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

/// Block
/**
* Klasa z odwolaniem do klasy skladowej jezyka sfml zawierajaca funkcje 
* Konstruktor z 4 parametrami
* Funkcja usuwajaca domyslny konstruktor
* Funkcja dodajaca nie domyslnego destruktora
* Funkcja werktorowa
* Funkcaj wirtualna
* Funkcja domyslanie zwracajca false
*/

class Block : public Drawable
{
public:
	Block(float t_X, float t_Y, float t_Width, float t_Height);
	Block() = delete;
	~Block() = default;

	void update();
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();
	Vector2f getSize();

private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;  ///funkcja wirtualna ,,,,const override 
	RectangleShape shape;
	bool destroyed{ false }; /// funkja ktora domysle zwraca false
};

