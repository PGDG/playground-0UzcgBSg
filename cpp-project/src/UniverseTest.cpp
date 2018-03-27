#include "Exercises/Universe.cpp"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

static int somme(int op1, int op2);

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

// check if a string exists in a text file
bool ExistsInFile(string str, string filename) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        if (line.find(str) != string::npos ) {
            return true;
        }
    }

    return false;
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
        AssertEquals(7, somme(op1,op2), "Running Universe::somme(2, 5)...");

        int op3 =3, op4=-3;
        AssertEquals(0, somme(op3,op4), "Running Universe::somme(3, -3)...");
        Success(true);

        if (ExistsInFile("accumulate", "src/Exercises/Universe.cpp")) {
            Message("My personal Yoda, you are. 🙏", "* ● ¸ .　¸. :° ☾ ° 　¸. ● ¸ .　　¸.　:. • ");
            Message("My personal Yoda, you are. 🙏", "           　★ °  ☆ ¸. ¸ 　★　 :.　 .   ");
            Message("My personal Yoda, you are. 🙏", "__.-._     ° . .　　　　.　☾ ° 　. *   ¸ .");
            Message("My personal Yoda, you are. 🙏", "'-._\\7'      .　　° ☾  ° 　¸.☆  ● .　　　");
            Message("My personal Yoda, you are. 🙏", " /'.-c    　   * ●  ¸.　　°     ° 　¸.    ");
            Message("My personal Yoda, you are. 🙏", " |  /T      　　°     ° 　¸.     ¸ .　　  ");
            Message("My personal Yoda, you are. 🙏", "_)_/LI");
        } else {
            Message("Kudos 🌟", "Did you know that you can use the accumulate method to sum up a vector? Try it!");
            Message("Kudos 🌟", " ");
            Message("Kudos 🌟", "#include <numeric>");
            Message("Kudos 🌟", " ");
            Message("Kudos 🌟", "vector<int> galaxies {37, 3, 2};");
            Message("Kudos 🌟", "int totalStars = accumulate(galaxies.begin(), galaxies.end(), 0); // 42");
        }

    } catch (const exception& e)  {
        Success(false);
        Message("Oops! 🐞", e.what());
        Message("Hint 💡", "Il faut faire la somme des deux opérandes passées en argument 🤔");
    }

  return 0;
}
