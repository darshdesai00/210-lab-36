#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main() {

    IntBinaryTree tree;

    cout << "Testing string BST...\n";

    tree.insertNode("ABC123");
    tree.insertNode("HELLO1");
    tree.insertNode("Z9X8");
    tree.insertNode("CODE55");
    tree.insertNode("APPLE22");

    cout << "\nInorder traversal (alphabetical):\n";
    tree.displayInOrder();

    return 0;
}

