#ifndef CONTROL_H
#define CONTROL_H
#include "Dictionary.h"


struct Player{
  char type;
  std::string name;
  int score;
  Player(char t, std::string n, int s ) : type(t), name(n), score(s) {};
  Player(){};
};

struct fallingWord{
  std::string word;
  int x;
  int y;
};


enum GameState{ MENU, SCOREBOARD, RUNNING_EASY, RUNNING_MEDIUM, RUNNING_HARD, FINISHED };


class GameControl{
  Dictionary & dictionary;
  Player p;
  std::vector<fallingWord> fallingWords;
  GameState state;
  Player scoresEasy[10];
  Player scoresMedium[10];
  Player scoresHard[10];
  void addWord(char diff);
  void lossCheck();
  sf::Font fontToCheck;
  sf::Text sizeCheck;
  std::default_random_engine defEngineCtrl;

public:
  explicit GameControl(Dictionary & d);
  void loadScores();
  void debug_printScores(char diff) const;
  void sortScores();
  Player* getScores(char diff);
  void setState(GameState deltaState);
  GameState getState() const;
  void setPlayerDiff(char diff);
  std::vector<fallingWord> getWords() const;
  void updateWords(char diff);
  void checkWord(std::string typedWord);
  int getPlayerScore() const;











};













#endif
