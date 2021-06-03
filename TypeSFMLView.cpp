#include <iostream>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Dictionary.h"
#include "GameControl.h"
#include "TypeSFMLView.h"

TypeSFMLView::TypeSFMLView(GameControl &c, Dictionary &d): control(c), dictionary(d){
  
  if(! font.loadFromFile("../resources/ARIAL.TTF")){
  abort();
  }

  text.setFont(font);
  text.setCharacterSize(40);

  scoreboardText.setFont(font);
  scoreboardText.setCharacterSize(15);

  fieldMenuE.setFillColor(sf::Color(60,60,60));
  fieldMenuE.setOutlineThickness(1);
  fieldMenuE.setOutlineColor(sf::Color(110,110,110));

  fieldMenuM.setFillColor(sf::Color(60,60,60));
  fieldMenuM.setOutlineThickness(1);
  fieldMenuM.setOutlineColor(sf::Color(110,110,110));

  fieldMenuH.setFillColor(sf::Color(60,60,60));
  fieldMenuH.setOutlineThickness(1);
  fieldMenuH.setOutlineColor(sf::Color(110,110,110));

  fieldMenuS.setFillColor(sf::Color(60,60,60));
  fieldMenuS.setOutlineThickness(1);
  fieldMenuS.setOutlineColor(sf::Color(110,110,110));

  fieldScoreboardM.setFillColor(sf::Color(60,60,60));
  fieldScoreboardM.setOutlineThickness(1);
  fieldScoreboardM.setOutlineColor(sf::Color(110,110,110));

}

void TypeSFMLView::centerOriginText(sf::Text & t){
  // centrowanie tekstu, metoda oparta na https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
  t.setOrigin(t.getLocalBounds().left + t.getLocalBounds().width/2, t.getLocalBounds().top + t.getLocalBounds().height/2);
}

void TypeSFMLView::drawMenu(sf::RenderWindow & win){
  text.setString(L"Łatwy");


  centerOriginText(text);
  text.setPosition(800/2,600/5);

  fieldMenuE.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  fieldMenuE.setOrigin(fieldMenuE.getLocalBounds().left + fieldMenuE.getLocalBounds().width/2, fieldMenuE.getLocalBounds().top + fieldMenuE.getLocalBounds().height/2);
  fieldMenuE.setPosition(text.getPosition());
  win.draw(fieldMenuE);
  win.draw(text);

  text.setString(L"Średni");
  
 
  centerOriginText(text);
  text.setPosition(sf::Vector2f(800/2,600/5*2));

  fieldMenuM.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  fieldMenuM.setOrigin(fieldMenuM.getLocalBounds().left + fieldMenuM.getLocalBounds().width/2, fieldMenuM.getLocalBounds().top + fieldMenuM.getLocalBounds().height/2);
  fieldMenuM.setPosition(text.getPosition());
  win.draw(fieldMenuM);
  win.draw(text);


  text.setString(L"Trudny");
  

  centerOriginText(text);
  text.setPosition(sf::Vector2f(800/2,600/5*3));

  fieldMenuH.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  fieldMenuH.setOrigin(fieldMenuH.getLocalBounds().left + fieldMenuH.getLocalBounds().width/2, fieldMenuH.getLocalBounds().top + fieldMenuH.getLocalBounds().height/2);
  fieldMenuH.setPosition(text.getPosition());
  win.draw(fieldMenuH);
  win.draw(text);

  text.setString(L"Tablica wyników");
  

  centerOriginText(text);
  text.setPosition(sf::Vector2f(800/2,600/5*4));

  fieldMenuS.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  fieldMenuS.setOrigin(fieldMenuS.getLocalBounds().left + fieldMenuS.getLocalBounds().width/2, fieldMenuS.getLocalBounds().top + fieldMenuS.getLocalBounds().height/2);
  fieldMenuS.setPosition(text.getPosition());
  win.draw(fieldMenuS);
  win.draw(text);
}

void TypeSFMLView::drawScoreboard(sf::RenderWindow & win){
  text.setString(L"TABELA REKORDÓW");
  centerOriginText(text);
  text.setPosition(sf::Vector2f(800/2,100));
  win.draw(text);



  for(int i = 0; i<10; i++){
    scoreboardText.setString(std::to_string(i+1));
    scoreboardText.setPosition(70, 150+i*30);
    win.draw(scoreboardText);

    scoreboardText.setString(control.getScores('e')[i].name);
    scoreboardText.setPosition(100, 150+i*30);
    win.draw(scoreboardText); 

    scoreboardText.setString(std::to_string(control.getScores('e')[i].score));
    scoreboardText.setPosition(200, 150+i*30);
    win.draw(scoreboardText);
  }

  for(int i = 0; i<10; i++){
    scoreboardText.setString(std::to_string(i+1));
    scoreboardText.setPosition(300, 150+i*30);
    win.draw(scoreboardText);

    scoreboardText.setString(control.getScores('m')[i].name);
    scoreboardText.setPosition(330, 150+i*30);
    win.draw(scoreboardText); 

    scoreboardText.setString(std::to_string(control.getScores('m')[i].score));
    scoreboardText.setPosition(430, 150+i*30);
    win.draw(scoreboardText);
  }

  for(int i = 0; i<10; i++){
    scoreboardText.setString(std::to_string(i+1));
    scoreboardText.setPosition(530, 150+i*30);
    win.draw(scoreboardText);

    scoreboardText.setString(control.getScores('h')[i].name);
    scoreboardText.setPosition(560, 150+i*30);
    win.draw(scoreboardText); 

    scoreboardText.setString(std::to_string(control.getScores('h')[i].score));
    scoreboardText.setPosition(660, 150+i*30);
    win.draw(scoreboardText);
  }

  text.setString("MENU");
  centerOriginText(text);
  text.setPosition(800/2, 500);

  fieldScoreboardM.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  fieldScoreboardM.setOrigin(fieldScoreboardM.getLocalBounds().left + fieldScoreboardM.getLocalBounds().width/2, fieldScoreboardM.getLocalBounds().top + fieldScoreboardM.getLocalBounds().height/2);
  fieldScoreboardM.setPosition(text.getPosition());
  win.draw(fieldScoreboardM);
  win.draw(text);

}

void TypeSFMLView::handleEventMenu(sf::Event & event, sf::RenderWindow & win){
  if (event.type == sf::Event::MouseButtonPressed)
  {
    if (event.mouseButton.button == sf::Mouse::Left)
    {
      if (fieldMenuE.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))){
        std::cout << "Easy shape contains mouse position." << std::endl;
      }
      if (fieldMenuM.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))){
        std::cout << "Medium shape contains mouse position." << std::endl;
      }
      if (fieldMenuH.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))){
        std::cout << "Hard shape contains mouse position." << std::endl;
      }
      if (fieldMenuS.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))){
        control.setState(SCOREBOARD);
      }
    }
  }
}

void TypeSFMLView::handleEventScoreboard(sf::Event & event, sf::RenderWindow & win){
  if (event.type == sf::Event::MouseButtonPressed){
    if (event.mouseButton.button == sf::Mouse::Left){
      if (fieldScoreboardM.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))){
        control.setState(MENU);
      }
    }
  }
}


