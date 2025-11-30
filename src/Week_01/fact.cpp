#include <iostream>
using namespace std;

int main()
{
    
    int choice, n;
    long long fact;

    cout << "\n-- Factorial Calculator --";
    cout << "\n1. For loop";
    cout << "\n2. While loop";
    cout << "\n3. Do-While loop";
    cout << "\n4. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter a number: ";
            cin >> n;
            fact = 1;
            for (int i = 1; i <= n; i++)
                fact *= i;
            cout << "Factorial of " << n << " (using for loop) is " << fact << endl;
            break;
        }

        case 2:
        {
            cout << "Enter a number: ";
            cin >> n;
            fact = 1;
            int i = 1;
            while (i <= n)
            {
                fact *= i;
                i++;
            }
            cout << "Factorial of " << n << " (using while loop) is " << fact << endl;
            break;
        }

        case 3:
        {
            cout << "Enter a number: ";
            cin >> n;
            fact = 1;
            int i = 1;
            if (n == 0)
                fact = 1;
            else
            {
                do
                {
                    fact *= i;
                    i++;
                } while (i <= n);
            }
            cout << "Factorial of " << n << " (using do-while loop) is " << fact << endl;
            break;
        }

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid choice.\n";
        }

    } while (choice != 4);

    return 0;
}