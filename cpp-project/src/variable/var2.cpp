// { autofold
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

string output = "";

void println(char c){
    output << c << endl;
}
void print(char c){
    output << c ;
}

void Message(string msg) {
    stringstream ss(msg);
    string line;
    while (getline(ss, line, '\n')) {
        cout << "TECHIO> message --channel \"Output\" \"" << line << "\"" << endl;
    }
}

// Ecrire ici les tests permettant de valider le programme 
int main() {
  //}
  
//écrir ici
    
// { autofold
  Message(output);
  return 0;
}
//}
