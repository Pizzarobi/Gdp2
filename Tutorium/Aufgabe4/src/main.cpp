/*
  Tutorium Grundlagen der Programmierung 2 - Tutorium
  Aufgabe 4
*/

#include <iostream>
#include <string>

// Gibt eine Fehlermeldung aus und beendet das Programm.
void error() {
  std::cerr << "Ungültiger Term eigegeben." << std::endl;
  
  exit(1);
}

// Wandelt einen String zu einer Zahl um und macht eine Fehlerbehandlung.
int stringToZahl(const std::string &string) {
  int resultat;

  try {
    resultat = std::stoi(string);
  } catch (std::exception &e) {
    error();
  }

  return resultat;
}

int main() {
  std::string term;

  std::cout << "Geben Sie einen Term ein: ";
  std::getline(std::cin, term);

  /* Fügen Sie hier Ihren Code ein. */
  
  int resultat;

  /* Fügen Sie hier Ihren Code ein. */
  
  // Ausgabe.
  std::cout << "Das Resultat lautet: " << resultat << std::endl;

  return 0;
}
