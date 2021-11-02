#include "transition.h"

Transition::Transition(State* current_, std::string input_, std::string output_, State* next_,  std::string move_, int id_) {
  current = current_;
  input = input_;
  output = output_;
  next = next_;
  move = move_;
  id = id_;
}

int Transition::getId() {
  return id;
}

void Transition::print() {
  std::cout << id << ". δ(" << current -> getId() << ", " <<
  input << ") = ("<< next -> getId() << ", " <<
  output << "," << move << ")\n";
}


bool Transition::checkAlphabet(Alphabet& cinta) {
  return (cinta.check(input) && cinta.check(output));
}

State* Transition::getNext() {
  return next;
}

std::string Transition::getOutput() {
  return output;
}

std::string Transition::getInput() {
  return input;
}

bool Transition::isNull() {
  return (current == NULL || next == NULL);
}

bool Transition::canTransitate(State* now, std::string in) {
  return (now == current && input == in);
}

std::string Transition::getMove() {
  return move;
}