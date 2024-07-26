#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Display {
protected:
public:
    int num;
    void menu() {
        cout << "1) Book a room " << endl;
        cout << "2) Display the student previous record " << endl;
        cout << "3) Check rooms Availability " << endl;
        cout << "4) Personal updation of each month " << endl;
        cout << "5) View personal updation record" << endl;
        cout << "6) Exit " << endl << endl;

        cout << "Enter the number : ";
        cin >> num;
    }
};

class BookR : public Display {
protected:
    int a, b, c;
    string name, name1, name2, name3, num1, num2, num3, num4, num5, num6, num7;

public:
    void statusR() {
        cout << "\t\t\t\tWhich Room do you want to prefer  " << endl;
        cout << "1) Full room " << endl;
        cout << "2) 2 seater room " << endl;
        cout << "3) 3 seater room " << endl;
        cout << "4) 4 seater room " << endl;
        cin >> b;
        cout << endl << endl;
    }

    void statusP() {
        cout << "1) The person is a student " << endl;
        cout << "2) The person is a worker " << endl;
        cin >> a;

        if (a == 1 || a == 2) {
            cout << "Enter the name of the student : ";
            cin >> name;
            cout << endl;
            cout << "Enter the father or guardian name : ";
            cin >> name1;
            cout << endl;
            while(num1.length() != 15 || num1[5] != '-' || num1[13] != '-') {
                cout << "Invalid input" << endl;
                cout << "Enter Student's CNIC number (00000-0000000-0): ";
                cin >> num1;
            }
            cout << endl;
            cout << "Enter the Father's CNIC number (00000-0000000-0): ";
            cin >> num2;
            while(num2.length() != 15 || num2[5] != '-' || num2[13] != '-') {
                cout << "Invalid input" << endl;
                cout << "Enter the Father's CNIC number (00000-0000000-0): ";
                cin >> num2;
            }
            cout << endl;
            cout << "Enter Student's phone number (0000-0000000) :  ";
            cin >> num3;
            while(num3.length()!=12 || num3[4]!='-'){
            cout << "Invalid input" << endl;
            cout << "Enter Student's phone number (0000-0000000) :  ";
            cin >> num3;
			}
            cout << endl;
            cout << "Enter Father's phone number : ";
            cin >> num4;
            while(num4.length()!=12 || num4[4]!='-'){
            cout << "Invalid input" << endl;
            cout << "Enter Student's phone number (0000-0000000) :  ";
            cin >> num4;
			}
            cout << endl;
            if (a == 1) {
                cout << "Enter the name of Institution : " ;
                cin >> name2;
            }
            if (a == 2) {
                cout << "Enter the name of Work Place : " ;
                cin >> name3;
                
            }
            cout<<endl;
            cout << "Enter the date of booking (DD-MM-YYYY): ";
            cin >> num5;
            while(num5.length()!=10 || num5[2]!='-'|| num5[5]!='-'){
            cout<<"Invalid input"<<endl;
            cout << "Enter the date of booking (DD-MM-YYYY): ";
            cin >> num5;
			}
            cout << "Enter the amount paid: ";
            cin >> num6;
            cout << endl;
            cout << "Enter the amount pay date : ";
            cin >> num7;
            while(num7.length()!=10 || num7[2]!='-'|| num7[5]!='-'){
            cout<<"Invalid input"<<endl;
            cout << "Enter the date of booking (DD-MM-YYYY): ";
            cin >> num7;
			}
        }
    }

    void roomf() {
        ofstream outFile("booking_records.txt", ios::app);
        for (int i = 1; i <= 20; i++) {
            cout << i << "  ";
            if (i == 10) {
                cout << endl;
            }
        }
        cout<<endl;
        cout << "The Room number allotted is : ";
        cin >> c;

        if (outFile.is_open()) {
            outFile << "Room Number: " << c << "\n"
                    << "Name: " << name << "\n"
                    << "Father/Guardian Name: " << name1 << "\n"
                    << "Student CNIC: " << num1 << "\n"
                    << "Father CNIC: " << num2 << "\n"
                    << "Student Phone: " << num3 << "\n"
                    << "Father Phone: " << num4 << "\n"
                    << "Booking Date: " << num5 << "\n"
                    << "Amount Paid: " << num6 << "\n"
                    << "Payment Date: " << num7 << "\n\n";
            outFile.close();
        }
    }

    void roomA() {
        ifstream inFile("booking_records.txt");
        int bookedRooms[20] = {0};
        int roomNumber;
        string line;

        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                if (line.find("Room Number: ") != string::npos) {
                    stringstream ss(line.substr(13));  // Using stringstream to convert to int
                    ss >> roomNumber;
                    bookedRooms[roomNumber - 1] = 1;
                }
            }
            inFile.close();
        }

        cout << "Available room numbers are: "<<endl;
        for (int i = 1; i <= 20; i++) {
            if (!bookedRooms[i - 1]) {
                cout << i << "  ";
                if (i == 10) {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
};

class personalUP : public BookR {
protected:
    string identity, month, time;
    int amount, pass, date, dat;
    char value;

public:
    void updation() {
        cout << "Enter the password : ";
        cin >> pass;
        if (pass == 12345) {
            cout << "\t\t\t\tFull seater room price = 25000" << endl;
            cout << "\t\t\t\t2 seater room price = 22000" << endl;
            cout << "\t\t\t\t3 seater room price = 19000" << endl;
            cout << "\t\t\t\t4 seater room price = 16000" << endl << endl;

            cout << "Enter the name of month : ";
            cin >> month;
            cout << endl;
            cout << "Enter the name of the student : ";
            cin >> identity;
            cout << endl;
            cout << "Enter the amount given : ";
            cin >> amount;
            cout << endl;
            cout << "Enter the date : ";
            cin >> time;
            cout << endl;
            cout << "Someone wants to leave (y/n): ";
            cin >> value;
            if (value == 'y') {
                cout << "Enter the leaving month : ";
                cin >> date;
                cout << "Enter the leaving date : ";
                cin >> dat;
            }
            if (value == 'n') {
                writePersonalUpdationRecord(month, identity, amount, time);
            }
        } else {
            while (true) {
                cout << "Invalid password, enter again " << endl;
                cout << "Enter the password : ";
                cin >> pass;
                if (pass == 12345) {
                    updation();
                    break;
                }
            }
        }
    }

    void writePersonalUpdationRecord(string month, string identity, int amount, string time) {
        ofstream outFile("personal_updations.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Month: " << month << "\n"
                    << "Student: " << identity << "\n"
                    << "Amount: " << amount << "\n"
                    << "Date: " << time << "\n\n";
            outFile.close();
        } else {
            cout << "Unable to open file";
        }
    }

    void viewPersonalUpdationRecord() {
        ifstream inFile("personal_updations.txt");
        string line;

        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Unable to open file";
        }
    }
};

int main() {
    personalUP k;
    k.menu();
    if (k.num == 1) {
        k.statusR();
        k.statusP();
        k.roomf();
    }
    if (k.num == 2) {
        ifstream inFile("booking_records.txt");
        string line;
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        }
    }
    if (k.num == 3) {
        k.roomA();
    }
    if (k.num == 4) {
        k.updation();
    }
    if (k.num == 5) {
        k.viewPersonalUpdationRecord();
    }
    if (k.num == 6) {
        return 0;
    }
}

