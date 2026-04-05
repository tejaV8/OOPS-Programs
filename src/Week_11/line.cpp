#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/data.txt");
    if(fin.is_open()){
        string line;
        char ch;
        int count = 0;
        cout << "Enter the starting letter to count: ";
        cin >> ch;
        while(getline(fin, line)){
            if(!line.empty() && line[0] == ch){
                count++;
            }
        }
        fin.close();
        cout << "Number of lines starting with '" << ch << "' : " << count << endl;
    }
    else{
        cout << "Unable to open file." << endl;
    }
    return 0;
}