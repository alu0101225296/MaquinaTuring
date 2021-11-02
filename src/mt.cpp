#include "mt.h"

MT::MT() {
}

MT::MT(std::string file) {
  readData(file);
  checkData(); 
}

MT::~MT() {
}

State* MT::findState(std::string state_) {
  for(auto state : States)
      if(state -> getId() == state_) 
        return state;
  return NULL;
}

std::vector<std::string> MT::splitLine(std::string line) {
  std::istringstream ss(line); 
  std::string split;
  std::vector<std::string> processedLine;
  while(std::getline(ss, split, ' '))
    processedLine.push_back(split);
  return processedLine;
}

void MT::readData(std::string file) {  
  std::ifstream MTFile(file);
  std::string line;

  if(MTFile.is_open()) {
    while(std::getline(MTFile, line) && line[0] == '#') continue;

    for(auto state : splitLine(line))
      States.push_back(new State(state));
    
    std::getline(MTFile, line);
    for(auto token : splitLine(line))
      E.add(token);
    
    std::getline(MTFile, line);
    for(auto token : splitLine(line))
      cinta.T.add(token);
    
    std::getline(MTFile, line);
    initial_state = findState(line);
    currentState = initial_state;
      
    std::getline(MTFile, line); // AQUI  DOY POR HECHO QUE BLANCO ES . CAMBIAR SI HAY QUE PERSONALIZARLO
    
    std::getline(MTFile, line);
    for(auto token : splitLine(line))
      if(findState(token)) findState(token) -> setFinal();
        else {
          std::cout << "error estados finales\n";
          exit(EXIT_FAILURE);
        }


    std::vector<std::string> tline;
    std::vector<std::string> stack_push;
    int id = 1;
    while(std::getline(MTFile, line)) {
      tline = splitLine(line);
      transitions.push_back(new Transition(findState(tline[0]), tline[1], tline[3],
        findState(tline[2]), tline[4], id));
      id++;
    }
    
    MTFile.close();
  } else {
    std::cout << "Error al abrir fichero";
    exit(EXIT_FAILURE);
  }
}

void MT::checkData() {
  if(initial_state == NULL) {
    std::cout << "Estado inicial no forma parte del conjunto de estados";
    exit(EXIT_FAILURE);
  }

  for(auto t : transitions) {
    if(t -> isNull()) {
      std::cout << "Transición " << t -> getId() << " incorrecta (estado no existe)";
      exit(EXIT_FAILURE);
    }
    if(!t -> checkAlphabet(cinta.T)) {
      std::cout << "Transición " << t -> getId() << 
        " incorrecta (elemento no pertenece al alfabeto)";
      exit(EXIT_FAILURE);
    }
  } 
}

Transition* MT::getMove(State* now, std::string input) {
  for(auto t : transitions)
    if(t -> canTransitate(now, input))
      return t;
  return NULL;
}

void MT::run(std::string cadena) {
  cinta.insertInicio(cadena);

  while(getMove(currentState, cinta.current()) != NULL) {
    transit(getMove(currentState, cinta.current()));      
    cinta.print();
  } 
  if(currentState -> isFinal()) 
    std::cout << "Cadena aceptada\n";
  else std::cout << "Cadena no aceptada\n";
} 

void MT::transit(Transition* transition) {
  cinta.write(transition -> getOutput());
  cinta.move(transition -> getMove());
  currentState = transition -> getNext();
}

void MT::reset() {
  currentState = initial_state;
  cinta.reset();  
}

void MT::showInfo() {
  std::cout << "Estados: ";
  for(auto state : States) 
    std::cout << state -> getId() << "(" << state -> isFinal() << ") ";
  std::cout << "\n";
 
  std::cout << "Alfabeto de la entrada: ";
  E.print();

  std::cout << "Alfabeto de la cinta: ";
  cinta.T.print();

  std::cout << "Estado inicial: " << initial_state -> getId() << "\n";
  std::cout << "Símbolo blanco: " << "." << "\n"; // AQUI  DOY POR HECHO QUE BLANCO ES . CAMBIAR SI HAY QUE PERSONALIZARLO

  std::cout << "Transiciones:\n";
  for(auto t : transitions)
    t -> print();
}