///Block.cpp
/**
*Plik zawierajcy kod implementujcy bloki
* "#include "Block.h"" - plik naglowkowy
*/
#include "Block.h"  // plik naglowkowy  plik o kafelkach block:: to ssa metody klasy 

///Block::
/**
* Metoda klasy zawierajaca konstruktor
* Implementacja pozycji bloku na plaszcyznie oznaczona osiami "x" oraz "y"
* Implementacja rozmiaru bloku na planszy
* Implementacja koloru bloku na planszy
* Implementacja kontorow bloku
*/
Block::Block(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_Width, t_Height });
	shape.setFillColor(Color::Color(255, 0, 0));
	shape.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

///draw
/**
* Funkcja rysujaca blok
* Implementacja bloku za pomoca instrukji sfml
*/
void Block::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

///left
/**
* Typ zwracajacy pozycje kulki poprzez pobranie pozycji x i odjecia od srodka promienia co daje uzyskc pozycje lewej jej krawiedzi
*/

float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

///right
/**
* Typ zwracajacy pozycje kulki poprzez pobranie pozycji x i odjecia od srodka promienia co daje uzyskc pozycje prawej jej krawiedzi
*/

float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

///top
/**
* Typ zwracajacy pozycje kulki poprzez pobranie pozycji x i odjecia od srodka promienia co daje uzyskc pozycje gornrj jej krawiedzi
*/

float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

///bottom
/**
* Typ zwracajacy pozycje kulki poprzez pobranie pozycji x i odjecia od srodka promienia co daje uzyskc pozycje dolnej jej krawiedzi
*/

float Block::bottom()  //dno
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

///getPosition
/**
* Funkcja wektorowa
* Funkja zwraca pozycje bloku
*/

Vector2f Block::getPosition()
{
	return shape.getPosition();
}

///isDestoyed
/**
* Funkcja sprawdzajaca czy bloczek jest znisczony
*/

bool Block::isDestroyed()
{
	return this->destroyed;
}

///destroy
/**
* Funkcja niszczaca bloczek
*/

void Block::destroy() ///funkja niszczy
{
	this->destroyed = true;
}

///getSize
/**
* Funkcja wektrorowa
* Funkcja zwraca rozmiar bloku
*/

Vector2f Block::getSize()
{
	return shape.getSize();
}

///update 
/**
* Funkcja odswiezajaca
* Funkcja odswieza plansze po zniszczeniu bloku z aktualna pozycja pileczki
*/

void Block::update()
{

}