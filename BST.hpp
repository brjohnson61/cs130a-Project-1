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
    int height;
    int size;

public:
    BST(BST* other);
    BST();
    BST(Node* root);

    bool search(string word);
    void insert(string word);
    void remove(string word);
    void sort(void);
    void rangeSearch(string startWord, string endWord);

    
    
};
