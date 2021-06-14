#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include "Dictionary.h"

Dictionary::Dictionary(){
  defEngine.seed(time(0));
}

void Dictionary::loadWords(){
  std::ifstream inFile;
  inFile.open("../slowa.txt");

    if (inFile.fail()){
      std::cerr << "Blad przy otwieraniu pliku" << std::endl;
      exit(1);
    }

  std::string str;
    while (std::getline(inFile, str))
    { 

      if(str.size() > 0 && str.size() <= 11){
        easy.push_back(str);
      }
      if(str.size() > 11 && str.size() <= 14){
        medium.push_back(str);
      }
      if(str.size() > 14){
        hard.push_back(str);
      }
      
    }
  inFile.close();

  std::cout<<"Easy words loaded: "<<easy.size()<<std::endl;
  std::cout<<"Medium words loaded: "<<medium.size()<<std::endl;
  std::cout<<"Hard words loaded: "<<hard.size()<<std::endl;

//usuwanie nexline ze stringów
  for(int i = 0; i<easy.size(); i++){
    easy[i].pop_back();
  }
  for(int i = 0; i<medium.size(); i++){
    medium[i].pop_back();
  }
  for(int i = 0; i<hard.size(); i++){
    hard[i].pop_back();
  }

}

std::string Dictionary::getWord(char diff){

  
  if(diff == 'e'){
    std::uniform_int_distribution<int> index_picker(0,easy.size());
    return easy[index_picker(defEngine)];
  }  

  if(diff == 'm'){
    std::uniform_int_distribution<int> index_picker(0,medium.size());
    return medium[index_picker(defEngine)];
  }  

  if(diff == 'h'){
    std::uniform_int_distribution<int> index_picker(0,hard.size());
    return hard[index_picker(defEngine)];
  }

  return "____ERROR____";
}

void Dictionary::debug_dumpVector(char diff){
  if(diff == 'e'){
    for(int i = 0; i<easy.size(); i++){
      std::cout<<easy[i]<<std::endl;
    }
  }
  if(diff == 'm'){
    for(int i = 0; i<medium.size(); i++){
      std::cout<<medium[i]<<std::endl;
    }
  }
  if(diff == 'h'){
    for(int i = 0; i<hard.size(); i++){
      std::cout<<hard[i]<<std::endl;
    }
  }

}