# Data Structures in C++

These are data structures I have implemented in C++. Tests are contained at the end of the
individual files.

## Getting Started

First compile the .cpp files from the terminal inside the folder containing the source files.
For example:

```
g++ BinarySearchTree.cpp -o bst
```

Run the individual files for examples of the methods in the data structures.
For example, from the command line:

```
./bst
```

This source code was tested on Mac OSX using the g++ compiler.

In all files, to turn off debug message set

```
#define DEBUG 0
```

## Data Structures

### BinarySearchTree.cpp

An implementation of a Binary Search Tree. This is an unordered tree where the first
item inserted becomes the root.

From wikipedia, the Binary Search Tree has the following properties:

1. The left subtree of a node contains only nodes with keys less than the node’s key.
2. The right subtree of a node contains only nodes with keys greater than the node’s key.
3. The left and right subtree each must also be a binary search tree.
4. There must be no duplicate nodes.

I have implemented the search and insert functions recursively.

The time complexity for the Binary Search Tree is as follows:

| Algorithm   | Average   | Worst Case |
| ----------- | --------- | ---------- |
| **Space**   | O (n)     | O (n)      |
| **Search**  | O (log n) | O (n)      |
| **Insert**  | O(log n)  | O (n)      |
| **Delete ** | O (log n) | O (n)      |

## Acknowledgments

#### Binary Search Tree

(https://en.wikipedia.org/wiki/Binary_search_tree)
