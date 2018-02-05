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
    if(otherTree->getRoot() != NULL){
        this->root = new Node(otherTree->getRoot());
        if(this->getRoot()->rightIsNull()){
            this->getRoot()->setRight(NULL);
        }
        else{
            this->getRoot()->setRight(BST(otherTree->getRightTree()).getRoot())
        }
        if(this->getRoot()->leftIsNull()){
            this->getRoot()->setLeft(NULL);
        }
        else{
            this->getRoot()->setLeft(BST(otherTree->getLeftTree()).getRoot())
        }
    }
    else{
        this->root = NULL;
    }
}

BST::BST(Node* otherRoot){
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

bool BST::search(string word){
    if(this->getRoot() == NULL){
        return false;
    }
    else{
        if(this->getRoot()->getWord().compare(word) == 0){
            return true;
        }
        else if(this->getRoot()->getWord().compare(word) < 0){
            if(this->getRoot()->rightIsNull()){
                return false;
            }
            else{
                return this->getRightTree()->search(word);
            }
        }
        else{
            if(this->getRoot()->leftIsNull()){
                return false;
            }
            else{
                return this->getLeftTree()->search(word);
            }
        }
    }

}

void BST::insert(string word){
    
}

void BST::remove(string word){

}

void BST::sort(){

}

void BST::rangedSearch(){

}
