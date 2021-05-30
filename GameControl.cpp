#include <iostream>
#include <fstream>

#include "GameControl.h"

GameControl::GameControl(){
  state = MENU;
  Player p('e', "Empty", 0);
}

void GameControl::loadScores(){
  std::ifstream inFile;
  inFile.open("../scoreboard.txt");

  if (inFile.fail()){
    std::cerr << "Blad przy otwieraniu pliku" << std::endl;
    exit(1);
  }

  char type;
  std::string name;
  int score;
  
  int e = 0;
  int m = 0;
  int h = 0;

  for(int i = 0; i<30; i++){

    std::string str;

    std::getline(inFile,str);
    type = str[0];
    str.clear();
    std::getline(inFile,str);
    name = str;
    str.clear();
    std::getline(inFile,str);
    score = stoi(str);
    str.clear();

    

    if(type == 'e'){
      scoresEasy[e] = Player(type, name, score);
      e++;
    }

    if(type == 'm'){
      scoresMedium[m] = Player(type, name, score);
      m++;
    }

    if(type == 'h'){
      scoresHard[h] = Player(type, name, score);
      h++;
    }

    


  }

  inFile.close();
}

void GameControl::debug_printScores(char diff)const{
  if(diff == 'e'){
    for(int i=0;i<10;i++){
      std::cout<<scoresEasy[i].type<<std::endl;
      std::cout<<scoresEasy[i].name<<std::endl;
      std::cout<<scoresEasy[i].score<<std::endl;
    }
  }
  if(diff == 'm'){
    for(int i=0;i<10;i++){
      std::cout<<scoresMedium[i].type<<std::endl;
      std::cout<<scoresMedium[i].name<<std::endl;
      std::cout<<scoresMedium[i].score<<std::endl;
    }
  }
  if(diff == 'h'){
    for(int i=0;i<10;i++){
      std::cout<<scoresHard[i].type<<std::endl;
      std::cout<<scoresHard[i].name<<std::endl;
      std::cout<<scoresHard[i].score<<std::endl;
    }
  }
}