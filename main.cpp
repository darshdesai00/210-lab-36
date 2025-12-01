#include <iostream>
#include "IntBinaryTree.h"
#include <fstream>
#include <string>
using namespace std;

void showMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Add record\n";
    cout << "2. Delete record\n";
    cout << "3. Search for record\n";
    cout << "4. Modify record\n";
    cout << "5. Display records (inorder)\n";
    cout << "6. Quit\n";
    cout << "Enter option: ";
}

int main() {

    IntBinaryTree tree;
    ifstream infile("codes.txt");

    if(!infile){
        cout << "Error: Could not open codes.txt\n";
        return 1;
    }

    string code;

    cout << "Loading records from codes.txt...\n";
    while (infile >> code) {
        tree.insertNode(code);
    }

    infile.close();
    cout << "All records have been loaded.\n";
    
    int choice;
    string oldValue, newValue;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter code to add: ";
            cin >> code;
            tree.insertNode(code);
            cout << code << " added.\n";
            break;

        case 2:
            cout << "Enter code to delete: ";
            cin >> code;
            tree.remove(code);
            cout << code << " deleted (if it existed).\n";
            break;   // <-- REQUIRED FIX

        case 3:
            cout << "Enter code to search: ";
            cin >> code;
            if (tree.searchNode(code))
                cout << code << " FOUND.\n";
            else
                cout << code << " NOT found.\n";
            break;

        case 4:
            cout << "Enter existing code: ";
            cin >> oldValue;
            cout << "Enter new value: ";
            cin >> newValue;
            tree.remove(oldValue);
            tree.insertNode(newValue);
            cout << "Record updated.\n";
            break;

        case 5:
            cout << "\nDisplaying all records:\n";
            tree.displayInOrder();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 6);

    return 0;
}

