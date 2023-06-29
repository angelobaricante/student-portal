#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Node class
class Node {
public:
    string name;
    string srCode;
    string sub1;
    string sub2;
    string sub3;
    Node* next;
};

// Stores the head of the Linked List
Node* head = new Node();


// Check Function to check that if
// Record Already Exist or Not
bool check(string x) {
    // Base Case
    if (head == NULL)
        return false;

    Node* t = new Node;
    t = head;

    // Traverse the Linked List
    while (t != NULL) {
        if (t->srCode == x)
            return true;
        t = t->next;
    }

    return false;
}


// Function to insert the record
void insertRecord(string srCode,string name, string sub1, string sub2, string sub3) {
    // if Record Already Exist
    if (check(srCode)) {
        cout << "Student with this "
             << "record Already Exists\n";
        return;
    }

    // Create new Node to Insert Record
    Node* t = new Node();
    t->srCode = srCode;
    t->name = name;
    t->sub1 = sub1;
    t->sub2 = sub2;
    t->sub3 = sub3;
    t->next = NULL;

    // Insert at Begin
    if (head == NULL || (head->srCode >= t->srCode)) {
        t->next = head;
        head = t;
    }

    // Insert at middle or End
    else {
        Node* c = head;
        while (c->next != NULL
               && c->next->srCode < t->srCode) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << endl <<"Student record was \nadded successfully!" << endl;
    cout << "======================================" << endl;
}



// Function to search record for any
// students Record with roll number
void searchRecord(string srCode)
{
    // if head is NULL
    if (!head) {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else {
        Node* p = head;
        while (p) {
            if (p->srCode == srCode) {
            cout << "SR-code: " << p->srCode << endl;
            cout << "name: " << p->name << endl;
            cout << "Subject 1: " << p->sub1 << endl;
            cout << "Subject 2: " << p->sub2 << endl;
            cout << "Subject 3: " << p->sub3 << endl;
                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << endl << "No such Record Available\n";
    }
}

// Function to display the Student's
// Record
void showRecord()
{
    Node* p = head;
    if (p == NULL) {
        cout << "======================================" << endl;
        cout << "          Search a student" << endl;
        cout << "======================================" << endl;
        cout << "No Record "
             << "Available\n";
    }
    else {
        cout << "======================================" << endl;
        cout << "        Display all students" << endl;
        cout << "======================================" << endl;

        // Until p is not NULL
        while (p != NULL) {
            cout << "SR-code: " << p->srCode << endl;
            cout << "name: " << p->name << endl;
            cout << "Subject 1: " << p->sub1 << endl;
            cout << "Subject 2: " << p->sub2 << endl;
            cout << "Subject 3: " << p->sub3 << endl;
            cout << "======================================" << endl;
            p = p->next;
        }
    }
}

int main()
{
    head = NULL;
    string srCode, name, sub1, sub2, sub3;
    int choice, studentNum;

    cout << "======================================" << endl;
    cout << "      Student Management System" << endl;
    while (true) {
        cout << "======================================" << endl;
        cout << endl << "What do you want to do?" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Search for a student" << endl;
        cout << "3. Display all students" << endl;
        cout << "4. Exit the program" << endl;
        cout << endl << "======================================" << endl;
        cout << endl << "Enter the number of the task: ";

        if(!(cin >> choice)) {
            cout << endl << "Invalid choice. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            system("CLS");
            studentNum = 0;
            cout << "======================================" << endl;
            cout << "           Add a Student" << endl;
            cout << "======================================" << endl;
            cout << "No. of students you want to add: ";

            if(!(cin >> studentNum) || studentNum < 1) {
                cout << endl << "Invalid number. Please enter a positive integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            for(int i = 0; i < studentNum; i++) {
                cout << endl << "SR code: ";
                cin >> srCode;
                cout << endl << "Name: ";
                cin >> name;
                cout << endl << "Subject 1: ";
                cin >> sub1;
                cout << endl << "Subject 2: ";
                cin >> sub2;
                cout << endl << "Subject 3: ";
                cin >> sub3;
                insertRecord(srCode, name, sub1, sub2, sub3);
            }
        }
        else if (choice == 2) {
            system("CLS");
            cout << "======================================" << endl;
            cout << "        Search a Student" << endl;
            cout << "======================================" << endl;
            cout << "Enter SR code of Student: ";
            cin >> srCode;
            cout << endl;
            searchRecord(srCode);
        }
        else if (choice == 3) {
            system("CLS");
            showRecord();
        }
        else if (choice == 4) {
            system("CLS");
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}



