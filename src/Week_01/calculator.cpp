#include <iostream>
using namespace std;

float add(float a, float b)
{
    return a + b;
}

float sub(float a, float b)
{
    return a - b;
}

float mul(float a, float b)
{
    return a * b;
}

float divi(float a, float b)
{
    return a / b;
}

int main()
{
    int choice;
    float num1, num2, result;

    cout << "\n--- SIMPLE CALCULATOR ---\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = add(num1, num2);
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = sub(num1, num2);
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = mul(num1, num2);
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (num2 == 0)
                cout << "Error! Division by zero is not allowed.\n";
            else
            {
                result = divi(num1, num2);
                cout << num1 << " / " << num2 << " = " << result << endl;
            }
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid choice.\n";
        }

    } while (choice != 5);

    return 0;
}