#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Info {
public:
    string name, year, add, dob;
    float marks;
    long long tel_no;

    void accept();
    void display();
};

void Info::accept() {
    cout << "Enter the name: ";
    getline(cin, name);

    cout << "Enter the address: ";
    getline(cin, add);

    cout << "Enter the year: ";
    getline(cin, year);

    cout << "Enter telephone number: ";
    cin >> tel_no;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Marks: ";
    cin >> marks;

    cout << "Enter date of birth: ";
    cin.ignore(); // Clear the buffer before using getline
    getline(cin, dob);
}

void Info::display() {
    cout << "\n\nName: " << name;
    cout << "\nAddress: " << add;
    cout << "\nYear: " << year;
    cout << "\nTelephone number: " << tel_no;
    cout << "\nMarks: " << marks;
    cout << "\nDate of birth: " << dob;
}

int main() {
    int ch, n = 0, pos, flag = 0;
    Info o[50];
    string searchName;  // Move the declaration here

    do {
        cout << "\n\n==============";
        cout << "\n    MENU";
        cout << "\n==============";
        cout << "\n1. Accept";
        cout << "\n2. Display";
        cout << "\n3. Insert record";
        cout << "\n4. Search record";
        cout << "\n5. Delete record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        
        cin >> ch;
        
        // Clear the error state and ignore remaining characters
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (ch) {
            case 1:
                o[n].accept();
                n++;
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                    o[i].display();
                }
                break;

            case 3:
                cout << "\nEnter the position to insert record (1 to " << n + 1 << "): ";
                cin >> pos;
                if (pos >= 1 && pos <= n + 1) {
                    for (int i = n; i >= pos - 1; i--) {
                        o[i + 1] = o[i];
                    }
                    o[pos - 1].accept();
                    n++;
                } else {
                    cout << "\nInvalid position.";
                }
                break;

            case 4:
                cout << "Enter the name to be searched: ";
                getline(cin, searchName);

                for (int i = 0; i < n; i++) {
                    if (searchName == o[i].name) {
                        flag = 1;
                        o[i].display();
                        break;
                    }
                }

                if (flag == 0)
                    cout << "Sorry.. Record not found";
                flag = 0;
                break;

            case 5:
                cout << "\nEnter the position to delete record (1 to " << n << "): ";
                cin >> pos;
                if (pos >= 1 && pos <= n) {
                    for (int i = pos - 1; i < n - 1; i++) {
                        o[i] = o[i + 1];
                    }
                    cout << "\nRecord is deleted..";
                    n--;
                } else {
                    cout << "\nInvalid position.";
                }
                break;

            case 6:
                break;

            default:
                cout << "\nInvalid choice.";
        }
    } while (ch != 6);

    return 0;
}