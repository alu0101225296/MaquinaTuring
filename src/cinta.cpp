#include "cinta.h"

Cinta::Cinta() {
}

Cinta::Cinta(std::string s) {
}

Cinta::~Cinta() {
}

void Cinta::insertInicio(std::string) {

}

void Cinta::reset() {
  cinta.resize(0);
}

void Cinta::print() {
  for(auto t : cinta) std::cout << t;
  std::cout << std::endl;
}

std::string Cinta::current() {
  return cinta[pos];
}

void Cinta::write(std::string write_) {
  cinta[pos] = write_;
}

void Cinta::move(std::string movement) {
  if(movement == "R") right();
    else left();
}

void Cinta::right() {
  pos++;
  if(pos > cinta.size() - 1) 
    cinta.push_back(".");  // AQUI  DOY POR HECHO QUE BLANCO ES . CAMBIAR SI HAY QUE PERSONALIZARLO
}

void Cinta::left() { 
  if(pos > 0) pos--;
    else pos = 0;
}