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
        if(found == 42){
            error << message << ": ???"<< endl;
        }else{
            error << message << ": wrong value"<< endl;
        }
        throw logic_error(error.str());
    }
}

// Ecrire ici les tests permettant de valider le programme 
int char_MAX=42;
int char_MIN=42;
int unsigned_char_MAX=42;
int unsigned_char_MIN=42;
int int_MAX=42;
int int_MIN=42;
unsigned int unsigned_int_MAX=42;
unsigned int unsigned_int_MIN=42;
long long_MAX=42;
long long_MIN=42;
unsigned long unsigned_long_MAX=42;
unsigned long unsigned_long_MIN=42;

int main() {
  exo(char_MAX, char_MIN, unsigned_char_MAX, unsigned_char_MIN, int_MAX, int_MIN, unsigned_int_MAX, unsigned_int_MIN, long_MAX, long_MIN, unsigned_long_MAX, unsigned_long_MIN);
    try {
        AssertEquals(127, char_MAX, "char_MAX");
        AssertEquals(-128, char_MIN, "char_MIN");
        AssertEquals(255, unsigned_char_MAX, "unsigned_char_MAX");
        AssertEquals(0, unsigned_char_MIN, "unsigned_char_MIN");
        AssertEquals(32767, int_MAX, "int_MAX");
        AssertEquals(-32768, int_MIN, "int_MIN");
        AssertEquals(65535, unsigned_int_MAX, "unsigned_int_MAX");
        AssertEquals(0, unsigned_int_MIN, "unsigned_int_MIN");
        AssertEquals(2147483647, long_MAX, "long_MAX");
        AssertEquals(-2147483648, long_MIN, "long_MIN");
        AssertEquals(4294967295, unsigned_long_MAX, "unsigned_long_MAX");
        AssertEquals(0, unsigned_long_MIN, "unsigned_long_MIN");
      
        Success(true);

    } catch (const exception& e)  {
        Success(false);
        Message("Oops! 🐞", e.what());
        //Message("Hint 💡", "Il faut faire la somme des deux opérandes passées en argument à la fonction ! ");
    }

  return 0;
}
