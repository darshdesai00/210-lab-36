// Specification file for the IntBinaryTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

#include <iostream>
#include <string>
using namespace std;

// The IntBinaryTree class manages a binary tree of strings.
class IntBinaryTree {

private:
   
   // TreeNode is a private structure for IntBinaryTree nodes.
   struct TreeNode {
      string value;        // changed from int to string
      TreeNode *left;      // Pointer to left child node
      TreeNode *right;     // Pointer to right child node
   };

   // root points to the topmost node of the tree.
   TreeNode *root;      

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(const string&, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:

   IntBinaryTree() { root = nullptr; }

   ~IntBinaryTree() { destroySubTree(root); }

   // Functions modified to use strings instead of ints
   void insertNode(const string&);
   void remove(const string&);
   bool searchNode(const string&) const;

   // Traversals
   void displayInOrder() const     { displayInOrder(root); }
   void displayPreOrder() const    { displayPreOrder(root); }
   void displayPostOrder() const   { displayPostOrder(root); }
};


// Insert a string node at the correct position
void IntBinaryTree::insertNode(const string &item) {
   TreeNode *newNode = new TreeNode;
   newNode->value = item;
   newNode->left = newNode->right = nullptr;
   insert(root, newNode);
}

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);
   else
      insert(nodePtr->right, newNode);
}


// Delete entire subtree (Postorder)
void IntBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      destroySubTree(nodePtr->left);
      destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}


// Public remove()
void IntBinaryTree::remove(const string &item) {
   deleteNode(item, root);
}


// Search for a value in the BST
bool IntBinaryTree::searchNode(const string &item) const {
   TreeNode *nodePtr = root;

   while (nodePtr) {
      if (nodePtr->value == item)
         return true;
      else if (item < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}


// Delete a node from the BST
void IntBinaryTree::deleteNode(const string &item, TreeNode *&nodePtr) {
   if (!nodePtr)
      return;
   else if (item < nodePtr->value)
      deleteNode(item, nodePtr->left);
   else if (item > nodePtr->value)
      deleteNode(item, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


// Reattach children during deletion
void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;
      delete tempNodePtr;
   } 
   else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
   else {
      tempNodePtr = nodePtr->right;
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;

      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}


// Traversals
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);
      displayPreOrder(nodePtr->right);
   }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

#endif // INTBINARYTREE_H
