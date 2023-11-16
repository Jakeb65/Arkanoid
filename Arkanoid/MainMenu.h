///MainMenu.h
/**
* Plik naglowkowy zawierajacy klasy, konstruktory, desruktory, definicje oraz dyrektwy.
*/
#pragma once       
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
///Max_mian_menu
/**
* @def < defonicja maksymalnego rozmiaru menu jako 4>;
*/
#define Max_main_menu 4  ///deninujemy max rozmiar menu jako 4 ;

///MainMenu
/**
*@class <MainMenu> < klasa menu >
* Klasa zawiera:
 *konstruktor z dwoma parametrami ;
 *dodawnia destruktora
 *funkcje "draw" rysujaca okno;
 *funkcje "MoveUp","MoveDown" porusznia sie w gore i w dol;
 *funkje zwracajaca opcje ktora rostala wybrana;
 *styl trzciaki;
 *przypisanie rozmiaru menu
*/
class MainMenu
{
public:
	MainMenu(float width, float height);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~MainMenu();

private:
	int MainMenuSelected;
	Font font; 
	Text mainMenu[Max_main_menu];
};