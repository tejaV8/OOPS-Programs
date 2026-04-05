#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/source.txt");
    ofstream fout("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/destination.txt");

    if(fin.is_open() && fout.is_open()){
        char ch;
        while(fin.get(ch)){
            fout.put(ch);
        }
        fin.close();
        fout.close();
        cout << "File copied successfully." << endl;
    }
    else{
        cout << "Unable to open file." << endl;
    }
    return 0;
}