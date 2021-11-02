#ifndef MT_H
#define MT_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

#include <vector>
#include "state.h"
#include "cinta.h"
#include "transition.h"

class MT {  // SOLO L Y R, INFINITA POR DERECHA
 private:
  Alphabet E; // alfabeto de la entrada
  std::vector<State*> States; // conjunto de estados
  Cinta cinta; // cinta
  State* initial_state; // estado inicial
  std::vector<Transition*> transitions; // conjunto de transiciones
  State* currentState; // estado actual

 public:
  MT();
  MT(std::string);
  ~MT();
  void readData(std::string); // almacena datos del fichero
  void checkData(); // comprueba que todos los datos introducidos son correctos
  void showInfo(); // muestra informacion del automata
  std::vector<std::string> splitLine(std::string); // funcion para facilitar lectura
  State* findState(std::string); // busca estado por el id en el conjunto
  Transition* getMove(State*, std::string); // devuelve transicion
  void transit(Transition*); // transita al estado siguiente
  void run(std::string); // comprueba si la cadena pertence al lenguaje
  void reset(); // resetea automata al estado antes de introducir una cadena
};
#endif