// Transmitter
#include <iostream>
#include <string>
#include <fstream>

#define BIND_FILENAME "Program-Binding.txt"

using namespace std;

bool Val = false;
int main() {
    int count = 99999999;
    while (true) {
        count++;
        // write val to file
        if (count > 99999999) {
            // open a file in write mode.
            ofstream outfile;
            outfile.open(BIND_FILENAME);
            outfile << "VAL-" << Val;
            Val = !Val;
            count = 0;
        }
    }
}
