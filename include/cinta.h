#ifndef CINTA_H
#define CINTA_H
#include <vector>  
#include "alphabet.h"

class Cinta {
 private:
  Alphabet T; // alfabeto de la cinta
  std::vector<std::string> cinta;
  int pos; // posicion cabecera
  std::string blanco;
 public:
  Cinta();
  Cinta(std::string);
  ~Cinta();
  void insertInicio(std::string);
  void reset();
  void print();
  void write(std::string);
  void move(std::string);
  void right();
  void left();
  void setBlanco(std::string);
  std::string current();
  friend class MT;
};
#endif