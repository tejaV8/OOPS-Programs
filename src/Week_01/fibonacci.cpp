#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibonacciIterative(int n)
{
    int first = 0, second = 1, next;

    cout << "Fibonacci Series (Iterative): ";
    for (int i = 1; i <= n; i++)
    {
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}

int main()
{
    int choice, n;

    cout << "\n--- Fibonacci Menu ---\n";
    cout << "1. Fibonacci using Iteration\n";
    cout << "2. Fibonacci using Recursion\n";
    cout << "3. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter number of terms: ";
            cin >> n;
            fibonacciIterative(n);
            break;

        case 2:
            cout << "Enter number of terms: ";
            cin >> n;

            cout << "Fibonacci Series (Recursive): ";
            for (int i = 0; i < n; i++)
                cout << fibonacci(i) << " ";
            cout << endl;

            break;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}