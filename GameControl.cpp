#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <string.h>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "GameControl.h"

GameControl::GameControl(Dictionary & d): dictionary (d){
  state = MENU;
  Player p('e', "Empty", 0);
  if(! fontToCheck.loadFromFile("../resources/ARIAL.TTF")){
  abort();
  }
  sizeCheck.setFont(fontToCheck);
  sizeCheck.setCharacterSize(25);
  defEngineCtrl.seed(time(0));
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

GameState GameControl::getState() const{
  return state;
}

void GameControl::setPlayerDiff(char diff){
  p.type = diff;
}

std::vector<fallingWord> GameControl::getWords() const{
  return fallingWords;
}

void GameControl::addWord(char diff){
  std::string addedString = dictionary.getWord(diff);
    //    0-533 szerokość 
  sizeCheck.setString(addedString);
  sizeCheck.setOrigin(sf::Vector2f(0,0));

  std::uniform_int_distribution<int> x_rand(1,533-sizeCheck.getLocalBounds().width);
  fallingWord addedWord;
  addedWord.word = addedString;
  addedWord.x = x_rand(defEngineCtrl);
  addedWord.y = 0;
  fallingWords.push_back(addedWord);


}


void GameControl::updateWords(char diff){
  if(fallingWords.size() == 0){
    addWord(diff);
  }

  for(int i = 0; i<fallingWords.size();i++){
    fallingWords[i].y = fallingWords[i].y+10;
  }
  
  bool checkSpace = 0;
  
  for(int i = 0; i<fallingWords.size();i++){
    if(fallingWords[i].y<70){
      checkSpace = 1;
    }
  }

  if(checkSpace == 0){
    addWord(diff);
    checkSpace=0;
  }

  lossCheck();

}

void GameControl::checkWord(std::string typedWord){
  for(int i = 0; i<fallingWords.size();i++){
    if(typedWord==fallingWords[i].word){
      sizeCheck.setString(fallingWords[i].word);
      if(fallingWords[i].y+sizeCheck.getLocalBounds().height>200){
        p.score = p.score+1;
      }
      if(fallingWords[i].y+sizeCheck.getLocalBounds().height>400){
        p.score = p.score+1;
      }
      p.score = p.score+1;
      fallingWords.erase(fallingWords.begin()+i);
    }
  }
}

int GameControl::getPlayerScore() const{
  return p.score;
}

void GameControl::lossCheck(){
  for(int i=0;i<fallingWords.size();i++){
    sizeCheck.setString(fallingWords[i].word);
    if(fallingWords[i].y+sizeCheck.getLocalBounds().height>600){
      setState(FINISHED);
    }
  }
}
