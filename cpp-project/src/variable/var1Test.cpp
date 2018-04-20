#include "exo/var1.cpp"

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

void Success(bool success) {
    cout << "TECHIO> success " << (success ? "true" : "false") << endl;
}

void AssertEquals(int expected, int found, string message) {
    if(expected != found) {
        ostringstream error;
        error << message << " Expected: " << expected << ", Found: " << found  << endl;
        throw logic_error(error.str());
    }
}

// Ecrire ici les tests permettant de valider le programme 

static int int_MAX = 36;

int main() {
  exo();
    try {
        AssertEquals(42, int_MAX, "int_MAX ??");
      
        Success(true);

    } catch (const exception& e)  {
        Success(false);
        Message("Oops! 🐞", e.what());
        //Message("Hint 💡", "Il faut faire la somme des deux opérandes passées en argument à la fonction ! ");
    }

  return 0;
}
