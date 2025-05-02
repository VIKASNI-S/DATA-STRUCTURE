//Round-Robin Function
#include "round_robin.h"

int main() {
    cout << "Enter the fixed time slice: ";
    cin >> timeSlice;
    int choice, time;
    
    while (true) {
        cout << "\n1. Insert Process\n2. Execute\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter process execution time: ";
                cin >> time;
                insertProcess(time);
                displayQueue();
                break;
            case 2:
                executeProcess();
                displayQueue();
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
