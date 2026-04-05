#include <iostream>
using namespace std;

template<class T>

void bubbleSort(T a[], int n){
    for(int i = 0; i < n - 1; i++){
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

template<class T>
void display(T a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i] <<" ";
    }
    cout<<endl;
}

int main() {
    int a[] = {10, 30, 5, 9, 8, 7};
    float b[] = {11.3, 30.5, 596, 96, 89, 7.5};

    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);

    cout<<"Elements before sorting: "<<endl;
    display(a, size_a);
    display(b, size_b);


    bubbleSort(a, size_a);
    bubbleSort(b, size_b);


    cout<<"Elements after sorting: "<<endl;
    display(a, size_a);
    display(b, size_b);
    return 0;
}