#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream fin("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/data.txt", ios::in | ios::out);
    if(!fin.is_open()){
        cout<<"Unable to open file."<<endl;
        return 1;
    }

    char ch;
    long pos;
    while(!fin.eof()){
        fin.get(ch);
        if(ch == 'k' || ch == 'K'){
            fin.seekp(-1, ios::cur);
            fin.put('C');
            fin.flush();
        }
    }
    return 0;
}