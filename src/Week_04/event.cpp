#include <iostream>
#include <string>
using namespace std;

class Event {
    static int count, Max_events;
    string ename, venue;
    
public:
    int eid, no_of_participants;

    void eventRegistration();
    void eventDetails();
    static void eventCount();
};

int Event::count = 0;
int Event::Max_events = 10;

void Event::eventRegistration() {
    if (count >= Max_events) {
        cout << "\nEvent registration full!" << endl;
        return;
    }
    cin.ignore();
    cout << "Enter event name: ";
    getline(cin, ename);
    cout << "Enter venue: ";
    getline(cin, venue);
    cout << "Enter event ID: ";
    cin >> eid;
    cout << "Enter number of participants: ";
    cin >> no_of_participants;

    count++;
}

void Event::eventDetails() {
    cout << "\nEvent Name: " << ename << endl;
    cout << "Venue: " << venue << endl;
    cout << "Event ID: " << eid << endl;
    cout << "Participants: " << no_of_participants << endl;
}

void Event::eventCount() {
    cout << "\nTotal Events Registered: " << count << endl;
}

int main() {
    Event e[100];
    int ch, i = 0;

    cout << "Event Management System\n";

    while (1) {
        cout << "\n1. Register Event\n2. Show Event Details\n3. Show Total Event Count\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            if (i >= 100) {
                cout << "Event storage full!" << endl;
                break;
            }
            e[i].eventRegistration();
            i++;
            break;

        case 2: {
            if (i == 0) {
                cout << "No events to display!\n";
                break;
            }

            int searchId;
            cout << "Enter Event ID to search: ";
            cin >> searchId;

            bool found = false;
            for (int j = 0; j < i; j++) {
                if (e[j].eid == searchId) {
                    e[j].eventDetails();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Event Not Found!" << endl;
            break;
        }

        case 3:
            Event::eventCount();
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid Input!" << endl;
        }
    }
}
