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
    if(otherRoot != NULL){
        this->root = new Node(otherRoot);
        if(otherRoot->rightIsNull()){
            this->root->setRight(NULL);
        }
        else{
            this->root->setRight(BST(otherRoot->getRight()).getRoot());
        }
        if(otherRoot->leftIsNull()){
        this->root->setLeft(NULL);
        }
        else{
            this->root->setLeft(BST(otherRoot->getLeft()).getRoot());
        }
    }
    else{
        this->root = NULL;
    }
}

void BST::setRoot(Node* other){
    this->root = other;
}

Node* BST::getRoot(){
    return this->root;
}

bool searchNode(Node* root, string word){
    if(root == NULL){
        return false;
    }
    else{
        if(root->getWord().compare(word) == 0){
            return true;
        }
        else if(root->getWord().compare(word) < 0){
            if(root->getRight()->rightIsNull()){
                return false;
            }
            else{
                return searchNode(root->getRight(), word);
            }
        }
        else{
            if(root->getLeft()->leftIsNull()){
                return false;
            }
            else{
                return searchNode(root->getLeft(), word);
            }
        }
    }
}

bool BST::search(string word){
    searchNode(this->getRoot(), word);
}

void BST::insert(string word){
    
}

void BST::remove(string word){
    
}

void BST::sort(){

}

void BST::rangeSearch(string startWord, string endWord){

}
