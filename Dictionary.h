#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <random>
#include <ctime>

class Dictionary
{
  std::vector<std::string> easy;
  std::vector<std::string> medium;
  std::vector<std::string> hard;
  std::default_random_engine defEngine;

public:
  Dictionary();
  void loadWords();
  std::string getWord(char diff);
  void debug_dumpVector(char diff);
};















#endif


