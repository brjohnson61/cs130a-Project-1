//
//  BST.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//


#include <string>
#include <stdio.h>
#include "BST.hpp"


using namespace std;

BST::BST(BST* otherTree){
    BST(otherTree->getRoot());
}

BST::BST(Node* otherRoot){
    this->root = new Node(otherRoot);
    if(otherRoot->getRight() != NULL){
        this->root->setRight(BST(otherRoot->getRight()).getRoot());
    }
    if(otherRoot->getLeft() != NULL){
        this->root->setLeft(BST(otherRoot->getLeft()).getRoot());
    }
}

