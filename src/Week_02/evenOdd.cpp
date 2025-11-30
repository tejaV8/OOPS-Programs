#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout<<"Enter "<< n <<" elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nEven elements are: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << " ";
        }
    }

    cout << "\nOdd elements are: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}