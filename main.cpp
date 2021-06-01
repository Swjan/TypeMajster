#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Dictionary.h"
#include "GameControl.h"
#include "TypeSFMLView.h"



int main()
{
  Dictionary words;
  words.loadWords();


  GameControl ctrl;
  ctrl.loadScores();
  ctrl.sortScores();

  TypeSFMLView view(ctrl, words);







	sf::RenderWindow window(sf::VideoMode(800, 600), "TypeMajster");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(3);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        
        window.clear();
        view.drawMenu(window);
        window.display();
    }

  return 0;
} 
