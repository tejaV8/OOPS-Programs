#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream fin("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/data.txt");

    if (!fin) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string data = "", line = "";

    while (getline(fin, line)) {
        data += line + "\n";
    }

    fin.close();

    int size = data.length();

    for (int i = size - 1; i >= 0; i--) {
        cout << data[i];
    }

    return 0;
}