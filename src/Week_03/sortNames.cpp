#include<iostream>
#include<string>
using namespace std;

class SortNames{
public:
    string name;

    void sortList(SortNames arr[], int n);
    void display(SortNames arr[], int n);
};



void SortNames::sortList(SortNames arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i].name > arr[j].name){
                swap(arr[i].name, arr[j].name); 
            }
        }
    }
}

void SortNames::display(SortNames arr[], int n){
    cout << "\nSorted Names:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i].name << endl;
}



int main(){
    int n;
    cout<<"Enter number of names: ";
    cin>>n;
    cin.ignore();  // This is important to clear input buffer for getline()

    SortNames arr[n];

    cout<<"Enter "<<n<<" names:\n";
    for(int i = 0; i < n; i++)
        getline(cin, arr[i].name);   

    SortNames obj;
    obj.sortList(arr, n);
    obj.display(arr, n);

    return 0;
}
