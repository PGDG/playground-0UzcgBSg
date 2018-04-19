#include "Exercises/Universe.cpp"

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
int main() {
    try {
        AssertEquals(7, test, "Running somme(2, 5)...");
        
        AssertEquals(7, somme(2,5), "Running somme(2, 5)...");

        AssertEquals(0, somme(3,-3), "Running somme(3,-3)...");
        Success(true);

    } catch (const exception& e)  {
        Success(false);
        Message("Oops! 🐞", e.what());
        Message("Hint 💡", "Il faut faire la somme des deux opérandes passées en argument à la fonction ! ");
    }

  return 0;
}
