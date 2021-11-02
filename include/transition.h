#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include "state.h"
#include "alphabet.h"

class Transition {
 private:
  State* current;
  State* next;
  std::string input;
  std::string output;
  std::string move; 
  int id; // para identificar las transiciones en la traza
 public:
  Transition();
  Transition(State*, std::string, std::string, State*, std::string, int);
  ~Transition();
  void print();
  int getId();
  bool checkAlphabet(Alphabet&);
  State* getNext();
  std::string getOutput();
  std::string getInput();
  std::string getMove();
  bool isNull();
  bool canTransitate(State*, std::string);
};
#endif