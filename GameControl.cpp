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

void GameControl::sortScores(){


  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9-i; j++){
      if (scoresEasy[j].score < scoresEasy[j+1].score){
        Player temp = scoresEasy[j];
        scoresEasy[j] = scoresEasy[j+1];
        scoresEasy[j+1] = temp;
      }   
    }
  }

  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9-i; j++){
      if (scoresMedium[j].score < scoresMedium[j+1].score){
        Player temp = scoresMedium[j];
        scoresMedium[j] = scoresMedium[j+1];
        scoresMedium[j+1] = temp;
      }   
    }
  }

  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9-i; j++){
      if (scoresHard[j].score < scoresHard[j+1].score){
        Player temp = scoresHard[j];
        scoresHard[j] = scoresHard[j+1];
        scoresHard[j+1] = temp;
      }   
    }
  }
  
}

Player* GameControl::getScores(char diff){
  if(diff == 'e'){
    return scoresEasy;
  }
  if(diff == 'm'){
    return scoresMedium;
  }
  if(diff == 'h'){
    return scoresHard;
  }
}

void GameControl::setState(GameState deltaState){
  state = deltaState;
}


