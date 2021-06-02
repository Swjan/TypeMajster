#ifndef TYPESFMLVIEW_H__
#define TYPESFMLVIEW_H__

class TypeSFMLView
{
GameControl & control;
Dictionary & dictionary;

sf::RectangleShape fieldMenuE;
sf::RectangleShape fieldMenuM;
sf::RectangleShape fieldMenuH;
sf::RectangleShape fieldMenuS;
sf::Text text;
sf::Text scoreboardText;


sf::Font font;

void centerOriginText(sf::Text & t);

public:
  TypeSFMLView(GameControl & c , Dictionary & d);
  void drawMenu(sf::RenderWindow & win);
  void drawScoreboard(sf::RenderWindow & win);
	void drawRunning (sf::RenderWindow & win);
  void drawFinished (sf::RenderWindow & win);
  void handleEventMenu(sf::Event & event, sf::RenderWindow & win);
};

#endif