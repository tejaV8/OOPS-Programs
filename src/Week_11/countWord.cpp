#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("C:/Users/Win 11/Documents/OOPS-Programs/src/Week_11/data.txt");
    if(fin.is_open()){
        string word, target;
        int count = 0;
        cout<<"Enter the word to count: ";
        cin>>target;
        while(fin >> word){
            if(word == target)
                count++;
        }
        fin.close();
        cout<<"The word '"<<target<<"' appears "<<count<<" times in the file."<<endl;
    }
    else 
    {
        cout<<"Unable to open file."<<endl;
    }
    return 0;
}