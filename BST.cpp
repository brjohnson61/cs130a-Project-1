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
        if(otherTree->getRight() != NULL){
            this->right = BST(otherTree->getRight());
        }
        else{
            this->right = NULL;
        }
        if(otherTree->getLeft() != NULL){
            this->left = BST(otherTree->getLeft());
        }
        else{
            this->left = NULL;
        }
    }
    else{
        this->root = NULL;
        this->right = NULL;
        this->left = NULL;
    }
}

BST::BST(){
    this->right = NULL;
    this->left = NULL;
    this->root = new Node();
}

BST::BST(Node* otherRoot){
    this->right = NULL;
    this->left = NULL;
    if(otherRoot == NULL){
        this->root = NULL;
    }
    else{
        this->root = new Node(otherRoot);
    }
}

void BST::setRoot(Node* other){
    this->setRoot(other);
}

Node* BST::getRoot(){
    return this->root;
}

bool BST::search(string word){
    //Checks to see if root is not null
    if(this->getRoot() == NULL){
        return false;
    }
    else{
        if(this->getRoot()->getWord() == word){
            return true;
        }
        else if(this->getRoot()->getWord() < word){
            if(this->getRight() == NULL){
                return false;
            }
            else{
                return this->getRight()->search(word);
            }
        }
        else{
            if(this->getLeft() == NULL){
                return false;
            }
            else{
                return this->getLeft()->search(word);
            }
        }


    }
}

void BST::insert(string word){
    if(this->getRoot() == NULL){
        this->setRoot(new Node(word));
    }
    else{
        if(this->getRoot()->getWord() == word){
            this->getRoot()->incrementCount();
        }
        else if(this->getRoot()->getWord() < word){

        }
        else{

        }
    }
}

void BST::remove(string word){
    
}

void BST::sort(){

}

void BST::rangeSearch(string startWord, string endWord){

}
