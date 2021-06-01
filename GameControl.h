#ifndef CONTROL_H
#define CONTROL_H


struct Player{
  char type;
  std::string name;
  int score;
  Player(char t, std::string n, int s ) : type(t), name(n), score(s) {};
  Player(){};
};

enum GameState{ MENU, SCOREBOARD, RUNNING_EASY, RUNNING_MEDIUM, RUNNING_HARD, FINISHED };


class GameControl{
  Player p;
  GameState state;
  Player scoresEasy[10];
  Player scoresMedium[10];
  Player scoresHard[10];
public:
  GameControl();
  void loadScores();
  void debug_printScores(char diff) const;
  void sortScores();
  Player* getScores(char diff);
  void setState(GameState deltaState);












};













#endif
