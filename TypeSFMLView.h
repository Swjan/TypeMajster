#ifndef TYPESFMLVIEW_H__
#define TYPESFMLVIEW_H__

class TypeSFMLView
{
GameControl & control;
Dictionary & dictionary;

sf::RectangleShape field;
sf::Text text;


sf::Font font;

public:
  TypeSFMLView(GameControl & c , Dictionary & d);
  void drawMenu(sf::RenderWindow & win);
  void drawScoreboard(sf::RenderWindow & win);
	void drawRunning (sf::RenderWindow & win);
  void drawFinished (sf::RenderWindow & win);
  void handleEvent(sf::Event & event);
};

#endif