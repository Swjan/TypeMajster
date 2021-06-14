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
              view.handleEventRunning(event);
          }
          ctrl.updateWords('e');
          window.clear();
          view.drawRunning(window, 'e');
          window.display();
          break;
        }

        case RUNNING_MEDIUM:{
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed) 
                  window.close();
              view.handleEventRunning(event);
          }
          ctrl.updateWords('m');
          window.clear();
          view.drawRunning(window, 'm');
          window.display();
          break;
        }

        case RUNNING_HARD:{
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed) 
                  window.close();
              view.handleEventRunning(event);
          }
          ctrl.updateWords('h');
          window.clear();
          view.drawRunning(window, 'h');
          window.display();
          break;
        }
/*
        case FINISHED:{
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed) 
                  window.close();
              view.handleEventFinished(event);
          }
          window.clear();
          view.drawFinished(window);
          window.display();
          break;
        }
        */
      }
      
    }

  return 0;
} 
