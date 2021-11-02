#include <iostream>
#include <string>
#include "mt.h"

int main(int argc, char *argv[]) {
  if (argc == 2) { 
    std::string cadena;
    std::string file = argv[1];
    std::string path = "../test/";
    MT maquina(path + file);

    maquina.showInfo();
    std::cout << "\n\n";

    while(std::cin >> cadena && cadena != "exit") {
      maquina.run(cadena);
      maquina.reset();
      std::cout << "\n\n";
    }
  } else {
    std::cout << "introduzca fichero como argumento"; 
    return 0;
  }
}