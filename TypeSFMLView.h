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
sf::RectangleShape fieldScoreboardM;
sf::RectangleShape sideBoard;
sf::RectangleShape inputBackground;
sf::Text text;
sf::Text scoreboardText;
sf::Text multiplierTextY;
sf::Text multiplierTextR;
sf::Text fallingWordText;
sf::Vertex lineOne[2];
sf::Vertex lineTwo[2];

std::string inputWord;
sf::Text inputText;


sf::Font font;

void centerOriginText(sf::Text & t);

public:
  TypeSFMLView(GameControl & c , Dictionary & d);
  void drawMenu(sf::RenderWindow & win);
  void drawScoreboard(sf::RenderWindow & win);
	void drawRunning (sf::RenderWindow & win, char diff);
  void drawFinished (sf::RenderWindow & win);
  void handleEventMenu(sf::Event & event, sf::RenderWindow & win);
  void handleEventScoreboard(sf::Event & event, sf::RenderWindow & win);
  void handleEventRunning(sf::Event & event);

};

#endif