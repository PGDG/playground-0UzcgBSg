// { autofold
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void Message(string channel, string msg) {
    stringstream ss(msg);
    string line;
    while (getline(ss, line, '\n')) {
        cout << "TECHIO> message --channel \"" << channel << "\" \"" << line << "\"" << endl;
    }
}




// Ecrire ici les tests permettant de valider le programme 
int main() {
  //}
  
  // { autofold
  return 0;
}
//}
