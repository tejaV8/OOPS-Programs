#include <iostream>
using namespace std;

template<class T>

class Sort
{
    T arr[100];
    int n;
public:
    void getData(){
        cout<<"Enetr number of elements: ";
        cin>>n;
        cout<<"Eneter elements: ";
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
    }

    void sortData(){
        for(int i = 0; i < n - 1; i++){
            bool swapped = false;
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if(!swapped)
                break;
        }
    }
    void display(){
        cout<<"Sorted elements: "<<endl;
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Sort<int> obj;
    obj.getData();
    obj.sortData();
    obj.display();
    return 0;
}