//
//  BST.hpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <string>
#include "Node.hpp"

#endif /* BinarySearchTree_hpp */

using namespace std;


class BinarySearchTree{
public:
    BinarySearchTree(BinarySearchTree* tree);
    BinarySearchTree();
    BinarySearchTree(Node* root);
    Node* getRoot();
    void setRoot(Node* other);
    BinarySearchTree* getRight(void);
    BinarySearchTree* getLeft(void);
    BinarySearchTree* minimumRoot(void);
    bool searchTree(string word);
    void insertNode(string word);
    BinarySearchTree* deleteNode(string word);
    void sortTree(void);
    void rangeSearchTree(string begin, string end);
private:
    Node* root;
    BinarySearchTree* right;
    BinarySearchTree* left;
};
