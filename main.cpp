#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Dictionary.h"
#include "GameControl.h"



int main()
{
 Dictionary words;
  words.loadWords();

  words.debug_dumpVector('e');

GameControl ctrl;
ctrl.loadScores();
ctrl.debug_printScores('e');





	sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        
        window.clear();
        window.display();
    }

  return 0;
} 
