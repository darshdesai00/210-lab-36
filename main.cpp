#include <iostream>
#include "IntBinaryTree.h"
#include <fstream>
#include <string>
using namespace std;

int main() {

    IntBinaryTree tree;
    ifstream infile("codes.txt");

    if(!infile){
        cout << "Error: Could not open codes.txt\n";
        return 1;
    }

    cout << "Loading record from the codes.txt file...\n";

    string code;

    while (infile >> code) {
        tree.insertNode(code);
    }

    infile.close();
    cout << "All records have been loaded into the BST.\n\n";
    
    cout << "\nInorder traversal (alphabetical):\n";
    tree.displayInOrder();

    return 0;
}

