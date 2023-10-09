// Receiver
// Transmitter program must be running for this to work
#include <iostream>
#include <string>
#include <fstream>

#define BIND_FILENAME "Binding-File.txt"

using namespace std;

int main() {
    while (true) {
        // reads val from file
        ifstream infile; 
        infile.open(BIND_FILENAME);
        string text = "";
        char c;
        while (infile >> c) 
        {
            text.push_back(c);
        }

        // scans for variable name and it's respective value
        if (text.length() > 0) {
            string bufferSTR = "";
            string VarValue = "";
            for (int i = 0; i < text.length(); i++) {
                bufferSTR.push_back(text[i]);
                if ("VAL-" == bufferSTR) {
                    for (int j = i+1; j < text.length(); j++) {
                        if ('\n' != text[j]) {
                            VarValue.push_back(text[j]);
                        } else {
                            goto BREAKLOOP;
                        }
                    }
                }
            }
            BREAKLOOP:
            cout << "VAL: " << VarValue << "\n";
        }
    }
}
