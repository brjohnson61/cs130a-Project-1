//
//  BST.hpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <string>
#include "Node.hpp"

#endif /* BST_hpp */

using namespace std;


class BST{
    Node* root;
    BST* right;
    BST* left;
public:
    BST(BST* otherTree);
    BST();
    BST(Node* otherRoot);

    Node* getRoot();
    void setRoot(Node* other);
    BST* getRight(void);
    BST* getLeft(void);
    void setRight(BST* other);
    void setLeft(BST* other);
    void setRight(Node* other);
    void setLeft(Node* other);

    bool search(string word);
    void insert(string word);
    void remove(string word);
    void sort(void);
    void rangeSearch(string startWord, string endWord);
};
