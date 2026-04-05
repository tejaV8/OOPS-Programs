#include <iostream>
#include <string>
using namespace std;

int main()
{
    string phno;

    cout << "Enter mobile number with country code: ";
    getline(cin, phno);

    try
    {
        if(phno.length() < 13 || phno.length() > 14)
            throw out_of_range("Invalid phone number length!");

        if(phno[0] != '+')
            throw invalid_argument("Phone number must start with +");

        string mobile = phno.substr(phno.length() - 10);
        string ccode = phno.substr(0, 3);

        for(int i = 0; i < mobile.length(); i++)
        {
            if(!isdigit(mobile[i]))
                throw invalid_argument("Mobile number contains invalid characters!");
        }

        cout << "Valid phone number entered." << endl;
        cout << "Mobile number: " << ccode  <<" "<< mobile << endl;
    }
    catch(out_of_range &e)
    {
        cout << "Out of range error: " << e.what() << endl;
    }
    catch(invalid_argument &e)
    {
        cout << "Invalid input error: " << e.what() << endl;
    }

    return 0;
}