#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream fin("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/data.txt");

    if(fin.is_open()){
        char ch;
        int chars = 0, words = 0, lines = 0;

        while(fin.get(ch)){
            chars++;

            if(ch == ' ' || ch == '\n' || ch == '\t')
                words++;

            if(ch == '\n')
                lines++;
        }

        fin.close();

        cout<<"Characters: "<<chars<<endl;
        cout<<"Words: "<<words+1<<endl;
        cout<<"Lines: "<<lines+1<<endl;
    }
    else{
        cout<<"Unable to open file."<<endl;
    }

    return 0;
}