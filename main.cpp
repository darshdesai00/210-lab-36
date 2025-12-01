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
            break;
        
        
        
        
        }
    }
    return 0;
}

