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


  GameControl ctrl(words);
  ctrl.loadScores();
  ctrl.sortScores();

  TypeSFMLView view(ctrl, words);







	sf::RenderWindow window(sf::VideoMode(800, 600), "TypeMajster");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(3);

    while (window.isOpen())
    {
      sf::Event event;
      switch(ctrl.getState()){
      
        case MENU:{
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed) 
                  window.close();
              view.handleEventMenu(event, window);
          }
          
          window.clear();
          view.drawMenu(window);
          window.display();
          break;
        }

        case SCOREBOARD:{
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed) 
                  window.close();
              view.handleEventScoreboard(event, window);
          }
          
          window.clear();
          view.drawScoreboard(window);
          window.display();
          break;
        }

        case RUNNING_EASY:{
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed) 
                  window.close();
              view.handleEventEasy(event, window);
          }
          ctrl.updateWords('e');
          window.clear();
          view.drawEasy(window);
          window.display();
          break;

        }
      }
    }

  return 0;
} 
