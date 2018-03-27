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

int main() {
    try {
        int op1 =2, op2 =5;
        AssertEquals(7, somme(op1,op2), "Running somme(2, 5) ...");

        int op3 =3, op4=-3;
        AssertEquals(0, somme(op3,op4), "Running somme(3, -3) ...");

        Success(true);
        Message("Kudos 🌟", "La notion est visiblement bien comprise. Félicitations !");

    } catch (const exception& e)  {
        Success(false);
        Message("Oops! 🐞", e.what());
        Message("Hint 💡", "Il faut faire la somme des deux opérandes passées en argument !");
    }

  return 0;
}
