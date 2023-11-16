/** \file Poziom4.h
* Odpowiada za czwarty poziom
*/
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "MainMenu.h"
#include "Poziom4.h"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;
/// Szablon klasy
/**
* Funkcja z 2 argumentami szablonowymi, uniwersalna funckja, pozwoli nam sprawdzaæ kolizje miedzy roznymi obiektami
* Zwraca dana krawedz obiektu w pixelach
*/
template <class T1, class T2> bool isIntersecting4(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}
/// collisionTest4
/**
* Funckja z dwoma parametrami sprawdzajaca kolizje paletki i pileczki
* Sprawdza czy oba obiekty na siebie nachodza
* Zabawa grawitacja, losujemy w jaki sposob ma sie odbic pileczka od paletki
*/
bool collisionTest4(Paddle& paddle, Ball& ball)
{
    if (!isIntersecting4(paddle, ball))
        return false;

    srand(time(NULL));
    int liczba = (rand() % 3) + 1;
    switch (liczba)
    {
    case 1:
        ball.moveUp();
        break;
    case 2:
        ball.moveUp();
        break;
    case 3:
        ball.moveUp();
        break;
    }

}
/// collisionTest4
/**
* Funckja z dwoma parametrami sprawdzajaca kolizje bloku i pileczki
* Sprawdza czy oba obiekty na siebie nachodza
* Przy odpowiednim warunku zniszcz blok
* Zmienne float z dwoma metodami klasy
* Instrukcja warunkowa, sprawdza w jaki sposob powinna odbic sie pilka
*/
bool collisionTest4(Block& block, Ball& ball)
{
    if (!isIntersecting4(block, ball))
        return false;

    block.destroy();

    float overlapLeft{ ball.right() - block.left() };
    float overlapRight{ block.right() - ball.left() };

    float overlapTop{ ball.bottom() - block.top() };
    float overlapBottom{ block.bottom() - ball.top() };

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
    float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

    if (abs(minOverlapX) < abs(minOverlapY))
    {
        ballFromLeft ? ball.moveLeft() : ball.moveRight();
    }
    else
    {
        ballFromTop ? ball.moveUp() : ball.moveDown();
    }
}
/// isGameOver4
/**
* Instrukcja warunkowa, sprawdza czy pilka spadla na dol planszy
*/
bool isGameOver4(Ball& ball)
{
    if (ball.bottom() == 600)
    {
        return true;
    }
}


/// Start
/**
* Obiekt klasy o dwoch parametrach
* Obiekt klasy o dwoch parametrach
* Stworzenie okna window
* Ustalenie limitu klatek na sekunde
* Stworzenie eventu
* Stworzenie zawartosci bloczkow, okreslaja ich liczbe i wielkosc
* Stworzenie wektora obiektu klasy
* Implementacja liczby blokow
* Petla for rysujaca blocki na ekranie
* Stworzenie tekstur i dodanie kilku tekstur tla
* Stworzenie obiektu klasy do rysowania obrazu na ekranie
* Ustawienie rozmiaru tla
* Buforowanie dzwieku oraz jego implementacja
* Wlaczenie muzyki
* Petla while, ktora dziala tylko przy wlaczonym oknie menu
* Wyczyszczenie okna, narysowanie obrazu na ekranie, dodanie opcji odpowiadajacej za funkcjonalnosc okna
* Warunek sprawdzajacy czy okno zostalo zamkniete
* Wywolanie funkcji update oraz collisionTest dla pilki i paletki\
* Warunek, ktory sprawdza czy gra zostala przegrana
* Zatrzymanie muzyki, wylaczenie okna
* Stworzenie nowego okna
* Buforowanie nowych dzwiekow i ich implementacja
* Dodanie opoznienia dzwieku i wlaczenie go
* Petla while sprawdza czy nowe okno jest otwarte
* Stworzenie eventu
* Petla while sprawdza czy nowy event jest wlaczony - jesli nie to wylacza okno, jesli jest to czekaj na przycisk i wylacz okno
* Wyczysc ekran, narysuj tlo i wyswietl
* Zwroc wartosc -1
* Petla for, dla ktorej argumentow automatycznie jest przypisany typ
* Warunek, ktory sprawdza kolizje bloku i pileczki, jesli nastapi zmniejsza liczbe blokow
* Automatyczny iterator, usuwa blok w przypadku spelnienia warunku
* Warunek sprawdza czy liczba blokow jest rowna zero
* Otworz nowe okno z tlem i komunikatem
* Zwroc wartosc 2
* Narysuj na ekranie pilke, paletke i bloki
*/
int Poziom4::Start()
{
    Ball ball(100, 250);
    Paddle paddle(400, 550);
    RenderWindow window(VideoMode(800, 600), "Arcanoid - Poziom 4");
    window.setFramerateLimit(60);
    Event event;

    RectangleShape tloPrzegrana;
    tloPrzegrana.setSize(Vector2f(800, 600));
    Texture mainPrzegrana;
    mainPrzegrana.loadFromFile("Textury/przegrana.png");
    tloPrzegrana.setTexture(&mainPrzegrana);

    RectangleShape tloWygrana;
    tloWygrana.setSize(Vector2f(800, 600));
    Texture mainWygrana;
    mainWygrana.loadFromFile("Textury/wygrana.png");
    tloWygrana.setTexture(&mainWygrana);

    Sprite sprite11;
    Sprite sprite111;
    SoundBuffer buffer;
    buffer.loadFromFile("Audio/level4Audio.wav");
    Sound sound;
    sound.setBuffer(buffer);
    sound.setPlayingOffset(sf::seconds(5.f));
    sound.play();

    unsigned blocksX{ 8 }, blocksY{ 4 }, blockWidth{ 65 }, blockHeight{ 15 };
    vector<Block> blocks;
    int numberOfBlocks = blocksX * blocksY;

    for (int i = 0; i < blocksY; i++)
    {
        for (int j = 0; j < blocksX; j++)
        {
            blocks.emplace_back((j + 1) * (blockWidth + 20), (i + 2) * (blockHeight + 25), blockWidth, blockHeight);
        }
    }

    Texture Poziom4;
    Poziom4.loadFromFile("Textury/level4.png");
    Sprite sprite4;
    sprite4.setTexture(Poziom4);

    while (window.isOpen())
    {
        window.clear();
        window.draw(sprite4);
        window.pollEvent(event);

        if (event.type == Event::Closed)
        {
            window.close();
            break;
        }

        ball.update();
        paddle.update();
        collisionTest4(paddle, ball);
        if (isGameOver4(ball) == true)
        {
            sound.stop();
            window.close();
            RenderWindow Super(VideoMode(800, 600), "Przegrana");
            SoundBuffer bufferL;
            bufferL.loadFromFile("Audio/koniecAudio.wav");
            Sound soundL;
            soundL.setBuffer(bufferL);
            soundL.setPlayingOffset(sf::seconds(10.f));
            soundL.play();
            while (Super.isOpen())
            {
                Event aevent;
                while (Super.pollEvent(aevent))
                {
                    if (aevent.type == Event::Closed)
                    {
                        Super.close();
                    }
                    if (aevent.type == Event::KeyPressed)
                    {
                        if (aevent.key.code == Keyboard::Escape)
                        {
                            Super.close();
                        }
                    }
                }
                Super.clear();
                Super.draw(tloPrzegrana);
                Super.display();
            }
            exit(1);
            return 0;
        }


        for (auto& block : blocks)
        {
            if (collisionTest4(block, ball))
            {
                numberOfBlocks--;
                break;
            }
        }

        auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed(); });
        blocks.erase(iterator, end(blocks));

        if (numberOfBlocks == 0)
        {
            sound.stop();
            window.close();
            RenderWindow Super(VideoMode(800, 600), "Wygrana");
            SoundBuffer bufferW;
            bufferW.loadFromFile("Audio/wygranaAudio.wav");
            Sound soundW;
            soundW.setBuffer(bufferW);
            soundW.play();

            while (Super.isOpen())
            {
                Event aevent;
                while (Super.pollEvent(aevent))
                {
                    if (aevent.type == Event::Closed)
                    {
                        Super.close();
                    }
                    if (aevent.type == Event::KeyPressed)
                    {
                        if (aevent.key.code == Keyboard::Escape)
                        {
                            Super.close();
                        }
                    }
                }
                Super.clear();
                Super.draw(tloWygrana);
                Super.display();
            }
            return 5;
        }

        window.draw(ball);
        window.draw(paddle);

        for (auto& block : blocks)
        {
            window.draw(block);
        }

        window.display();

    }

}
