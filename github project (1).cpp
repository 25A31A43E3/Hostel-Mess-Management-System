#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int roomNo;
    string name;
    int breakfast, lunch, dinner;

    Student(int r, string n) {
        roomNo = r;
        name = n;
        breakfast = 0;
        lunch = 0;
        dinner = 0;
    }

    int totalBill() {
        return (breakfast * 40) + (lunch * 80) + (dinner * 100);
    }
};

vector<Student> students;

int findStudent(int room) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].roomNo == room) {
            return i;
        }
    }
    return -1;
}

void addStudent() {
    int room;
    string name;

    cout << "Enter Room Number: ";
    cin >> room;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, name);

    students.push_back(Student(room, name));

    cout << "Student Added Successfully\n";
}

void orderFood() {
    int room, choice, qty;

    cout << "Enter Room Number: ";
    cin >> room;

    int index = findStudent(room);

    if (index == -1) {
        cout << "Student Not Found\n";
        return;
    }

    cout << "\n----- MENU -----\n";
    cout << "1. Breakfast - Rs 40\n";
    cout << "2. Lunch - Rs 80\n";
    cout << "3. Dinner - Rs 100\n";

    cout << "Enter Choice: ";
    cin >> choice;

    cout << "Enter Quantity: ";
    cin >> qty;

    switch (choice) {
    case 1:
        students[index].breakfast += qty;
        break;

    case 2:
        students[index].lunch += qty;
        break;

    case 3:
        students[index].dinner += qty;
        break;

    default:
        cout << "Invalid Choice\n";
        return;
    }

    cout << "Food Ordered Successfully\n";
}

void displayBill() {
    int room;

    cout << "Enter Room Number: ";
    cin >> room;

    int index = findStudent(room);

    if (index == -1) {
        cout << "Student Not Found\n";
        return;
    }

    Student s = students[index];

    cout << "\n----- MESS BILL -----\n";
    cout << "Student Name : " << s.name << endl;
    cout << "Room Number  : " << s.roomNo << endl;

    cout << "\nFood Details\n";

    cout << "Breakfast : " << s.breakfast
         << " x 40 = " << s.breakfast * 40 << endl;

    cout << "Lunch     : " << s.lunch
         << " x 80 = " << s.lunch * 80 << endl;

    cout << "Dinner    : " << s.dinner
         << " x 100 = " << s.dinner * 100 << endl;

    cout << "\nTotal Bill : Rs " << s.totalBill() << endl;
}

void displayStudents() {
    if (students.empty()) {
        cout << "No Student Records Found\n";
        return;
    }

    cout << "\n----- STUDENT RECORDS -----\n";

    for (auto s : students) {
        cout << "Room No: " << s.roomNo
             << " | Name: " << s.name
             << " | Total Bill: Rs " << s.totalBill()
             << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== HOSTEL MESS MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Order Food\n";
        cout << "3. Display Bill\n";
        cout << "4. Display Student Records\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;

        case 2:
            orderFood();
            break;

        case 3:
            displayBill();
            break;

        case 4:
            displayStudents();
            break;

        case 5:
            cout << "Thank You\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}