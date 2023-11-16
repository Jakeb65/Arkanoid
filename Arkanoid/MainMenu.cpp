///MainMenu.cpp
/**
*Plik zawiera kod implementujacy cale menu. W pliku zostaly uzyte funkje, zmienne roznego typu oraz konstruktory.
*/
#include "MainMenu.h"  
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
///MainMenu
/**
* Implementacja przekazania przez konsruktor menu gry oraz stworzenie napisow widocznych w menu gry.
* Zaimplementowano tu wszystkie wartosci graficzne takie jak wielkosc ,kolor oraz tresc napisow.
*/
MainMenu::MainMenu(float width, float height)
{
	font.loadFromFile("Czcionki/czcionka.ttf");

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Graj");
	mainMenu[0].setCharacterSize(45);
	mainMenu[0].setPosition(360, 160);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Ustawienia");
	mainMenu[1].setCharacterSize(45);
	mainMenu[1].setPosition(280, 220);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("O grze");
	mainMenu[2].setCharacterSize(45);
	mainMenu[2].setPosition(340, 280);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Wyjscie");
	mainMenu[3].setCharacterSize(45);
	mainMenu[3].setPosition(325, 340);

	MainMenuSelected = -1;
}
///~MainMenu 
/**
* Implementacja klasy menu oraz destruktora menu.
*/
MainMenu::~MainMenu()
{

}
///draw
/**
* @param[in] <i> < zmienna okreslajaca polozenia aktualnego wskaznika w grze (podswietlenie).
* fukcja rysujaca menu ktora sprawdza w ktorym miejscu menu aktualnie znajduje sie wskaznik (podswietlenie tekstu).
*/
void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}
}
///MoveUp
/**
* Funkcja pozwalajaca na ruch do gory po glownym menu
* Kiedy wskaznik (podswietlenie) zostanie przesuniety przez uzytkownika program przestanie wskazywc aktualny wybor w menu gry a podsiwtli nowy.
* * Zastosowano instrukcje warunkowa "if".
*/
void MainMenu::MoveUp()		//ruch do g�ry
{
	if (MainMenuSelected - 1 >= 0)  ///jesli najedzimy na opcje to zmienia sie podswietlenie z poprzednie zmienia na kolor domyslny 
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}
///MoveDownu
/**
* Funkcja pozwalajaca na ruch w dol po glownym menu
* Kiedy wskaznik (podswietlenie) zostanie przesuniety przez uzytkownika program przestanie wskazywc aktualny wybor w menu gry a podsiwtli nowy.
* Zastosowano instrukcje warunkowa "if".
* Definiujemy maksymalny roamiar menu jako 4
*/

void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}
