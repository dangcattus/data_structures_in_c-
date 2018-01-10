//C++ class for the binary search Tree
/* Properties:
1. The left subtree of a node contains only nodes with keys less than the node’s key.
2. The right subtree of a node contains only nodes with keys greater than the node’s key.
3. The left and right subtree each must also be a binary search tree.
4. There must be no duplicate nodes.
*/

#include <iostream>
#include <stddef.h>

#define DEBUG 1

using namespace std;

class BinarySearchTree
{
  private:
//how to do the node thing
    class Node {
    public:
      Node(int m) {
        key = m;
        left = nullptr;
        right = nullptr;
      }
    Node* left;
    Node* right;
    Node* parent;

    int key;
    friend class BinarySearchTree;
  };
      Node * root;
      int size;

public:
  BinarySearchTree(int val) {
    root = nullptr;
    size = 0;
    insert(val);
  }

  ~BinarySearchTree() {}

  void insert(int i);
  void insertArray();
  void insert (Node* node, Node* subtree);

  int search(int key);
  Node* search (int val, Node* subtree);

  int remove(int i);
  int removeAtIndex(int index);

  bool isEmpty();
  int getSize();
};


void BinarySearchTree::insert(Node* node, Node* subtree) {
    if(node->key < subtree->key) {
      if (!subtree->left) {
        subtree->left = node;
        node->parent = subtree;
        if (DEBUG) cout << "Insert " << node->key << " at left " << subtree->key << endl;

      }
      else {
        insert(node, subtree->left);
      }
    }
    else if (node->key > subtree->key) {
      if (!subtree->right) {
        subtree->right = node;
        node->parent = subtree;
        if (DEBUG) cout << "Insert " << node->key << " at right " << subtree->key << endl;
      }
      else {
        insert(node, subtree->right);
      }
    }
    else {
      cout << "ERROR. BST cannot have duplicate keys " << endl;
      return;
    }
}

void BinarySearchTree::insert(int val) {
  Node * node = new Node(val);

  if (this->isEmpty()) {
    this->root = node;
    if (DEBUG) cout << "Insert " << val << " at root" << endl;
  }
  else {
    this->insert(node, this->root);
  }
  size++;
  return;
}


int BinarySearchTree::search(int val) {
    Node *node = nullptr;
    int returnVal = -1;
    if (!this->isEmpty()) {
      node = this->search(val, root);

    }
    else {
      cout << "Tree is empty" << endl;
      return -1;
    }
    //Check to see if nullptr returned
    if (!node) {
      cout << "No key " << val << " in Tree" << endl;
      return -1;
    }
    else {
      returnVal = node->key;
      cout << "Found key " << returnVal << " in tree" << endl;
    }
    return returnVal;
}

BinarySearchTree::Node* BinarySearchTree::search(int val, Node* subtree) {
  if (val == subtree->key) {
    return subtree;
  }
  else if ((val < subtree->key) && (subtree->left != nullptr)) {
    if (DEBUG)
      cout << "Search Left subtree of " << subtree->key << " for " << val << endl;
    return search(val, subtree->left);
  }
  else if ((val > subtree->key) && (subtree->right != nullptr)) {
    if (DEBUG)
      cout << "Search right subtree of " << subtree->key << " for " << val << endl;
    return search(val, subtree->right);
  }
  else {
    if (DEBUG)
      cout << "Subtree of " << subtree->key << " is null." << endl;
    return nullptr;
  }
}

bool BinarySearchTree::isEmpty() {
  return (size == 0);
}

int BinarySearchTree::getSize() {
  return this->size;
}

int main() {
  BinarySearchTree* bst = new BinarySearchTree(8);

  bst->insert(3);
  bst->insert(4);
  bst->insert(7);
  bst->insert(5);
  bst->insert(10);
  bst->insert(2);
  bst->insert(9);
  bst->insert(11);

cout << "Size : " << bst->getSize() << endl;
 bst->search(7);
 bst->search(2);
 bst->search(1);

  delete bst;
  return 0;
}