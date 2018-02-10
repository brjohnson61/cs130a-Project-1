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
            this->right = new BST(otherTree->getRight());
        }
        else{
            this->right = NULL;
        }
        if(otherTree->getLeft() != NULL){
            this->left = new BST(otherTree->getLeft());
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
    this->root = NULL;
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
    this->root = other;
}

Node* BST::getRoot(){
    return this->root;
}

BST* BST::getLeft(){
    return this->left;
}

BST* BST::getRight(){
    return this->right;
}

void BST::setRight(BST* other){
    this->right = other;
}

void BST::setLeft(BST* other){
    this->left = other;
}

void BST::setRight(Node* other){
    this->right = new BST(other);
}

void BST::setLeft(Node* other){
    this->left = new BST(other);
}

bool BST::search(string word){
    //Checks to see if root is not null
    if(this->getRoot() == NULL){
        return false;
    }
    else{
        //Case 1: word is equal to root.
        if(this->getRoot()->getWord() == word){
            return true;
        }
        //Case 2: word is greater than root.
        else if(this->getRoot()->getWord() < word){
            if(this->getRight() == NULL){
                return false;
            }
            else{
                return this->getRight()->search(word);
            }
        }
        //Case 3: word is less than root.
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
    else if(this->getRoot()->getWord().empty()){
        this->getRoot()->setWord(word);
        this->getRoot()->setCount(1);
    }
    else{
        if(this->getRoot()->getWord() == word){
            this->getRoot()->incrementCount();
        }
        else if(this->getRoot()->getWord() < word){
            if(this->getRight() == NULL){
                this->setRight(new BST());
            }
            this->getRight()->insert(word);
        }
        else{
            if(this->getLeft() == NULL){
                this->setLeft(new BST());
            }
            this->getLeft()->insert(word);
        }
    }
}

void BST::remove(string word){
    
}

void BST::sort(){

}

void BST::rangeSearch(string startWord, string endWord){

}
