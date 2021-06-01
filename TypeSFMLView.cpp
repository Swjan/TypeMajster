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
  field.setFillColor(sf::Color(60,60,60));
  field.setOutlineThickness(1);
  field.setOutlineColor(sf::Color(110,110,110));

}

void TypeSFMLView::drawMenu(sf::RenderWindow & win){
  text.setString(L"Łatwy");

  // centrowanie tekstu, metoda z https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
  text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width/2, text.getLocalBounds().top + text.getLocalBounds().height/2);
  text.setPosition(800/2,600/5);

  field.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  field.setOrigin(field.getLocalBounds().left + field.getLocalBounds().width/2, field.getLocalBounds().top + field.getLocalBounds().height/2);
  field.setPosition(text.getPosition());
  win.draw(field);
  win.draw(text);

  text.setString(L"Średni");
  
  // centrowanie tekstu, metoda oparta na https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
  text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width/2, text.getLocalBounds().top + text.getLocalBounds().height/2);
  text.setPosition(sf::Vector2f(800/2,600/5*2));

  field.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  field.setOrigin(field.getLocalBounds().left + field.getLocalBounds().width/2, field.getLocalBounds().top + field.getLocalBounds().height/2);
  field.setPosition(text.getPosition());
  win.draw(field);
  win.draw(text);


  text.setString(L"Trudny");
  
  // centrowanie tekstu, metoda oparta na https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
  text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width/2, text.getLocalBounds().top + text.getLocalBounds().height/2);
  text.setPosition(sf::Vector2f(800/2,600/5*3));

  field.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  field.setOrigin(field.getLocalBounds().left + field.getLocalBounds().width/2, field.getLocalBounds().top + field.getLocalBounds().height/2);
  field.setPosition(text.getPosition());
  win.draw(field);
  win.draw(text);

  text.setString(L"Tablica wyników");
  
  // centrowanie tekstu, metoda oparta na https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
  text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width/2, text.getLocalBounds().top + text.getLocalBounds().height/2);
  text.setPosition(sf::Vector2f(800/2,600/5*4));

  field.setSize(sf::Vector2f(text.getLocalBounds().width+10,text.getLocalBounds().height+10));
  field.setOrigin(field.getLocalBounds().left + field.getLocalBounds().width/2, field.getLocalBounds().top + field.getLocalBounds().height/2);
  field.setPosition(text.getPosition());
  win.draw(field);
  win.draw(text);
}
