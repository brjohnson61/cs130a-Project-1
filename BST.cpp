//
//  BST.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//


#include <string>
#include <stdio.h>
#include <iostream>
#include "BST.hpp"


using namespace std;

void outputFileWrite(string out){

}

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

BST* BST::minimumRoot(){
    if(this->getLeft() == NULL){
        return this;
    }
    else{
        return this->getLeft()->minimumRoot();
    }
}

void BST::printTree(){
    if(this->getLeft() != NULL){
        this->getLeft()->printTree();
    }
    this->getRoot()->printNode();
    if(this->getRight() != NULL){
        this->getRight()->printTree();
    }
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

void BST::insert(Node* other){
    if(this->getRoot() == NULL){
        this->setRoot(new Node(other));
    }
    else if(this->getRoot()->getWord().empty()){
        this->getRoot()->setWord(other->getWord());
        this->getRoot()->setCount(other->getCount());
    }
    else{
        if(this->getRoot()->getWord() == other->getWord()){
            this->getRoot()->setCount(this->getRoot()->getCount()+other->getCount());
        }
        else if(this->getRoot()->getWord() < other->getWord()){
            if(this->getRight() == NULL){
                this->setRight(new BST());
            }
            this->getRight()->insert(other);
        }
        else{
            if(this->getLeft() == NULL){
                this->setLeft(new BST());
            }
            this->getLeft()->insert(other);
        }
    }
}

BST* BST::remove(string word){
    if(this->root == NULL){
        return this;
    }
    
    if(this->getRoot()->getWord() == word){
        if(this->root->getCount() > 1){
            this->getRoot()->decrementCount();
            return this;
        }
        if(this->getRight()==NULL && this->getLeft()==NULL){
                delete this;
                return NULL;
        }
        else if((this->getRight() == NULL) != (this->getLeft() == NULL)){
            BST* temp;
            if(this->getRight()==NULL){
                temp = this->getLeft();
                this->left = NULL;
            }
            else{
                temp = this->getRight();
                this->right = NULL;
            }
            delete this;
            return temp;
        }
        else{
            BST* temp = this->getRight()->minimumRoot();
            
            this->getRoot()->setWord(temp->getRoot()->getWord());
            this->getRoot()->setCount(temp->getRoot()->getCount());

            this->setRight(this->getRight()->remove(this->getRoot()->getWord()));
            return this;
        }
    }
    else if(this->getRoot()->getWord() < word){
        if(this->getRight() == NULL){
            return this;
        }
        else{
            this->right = this->right->remove(word);
            return this;
        }
    }
    else{
        if(this->getLeft() == NULL){
            return this;
        }
        else{
            this->left = this->left->remove(word);
            return this;
        }
    } 
}

void BST::sort(){
    if(this->getLeft() != NULL){
        this->getLeft()->sort();
    }
    outputFileWrite(this->getRoot()->getWord());
    if(this->getRight() != NULL){
        this->getRight()->sort();
    }
}

void BST::rangeSearch(string startWord, string endWord){
    if(this->getRoot()->getWord() >= startWord && this->getRoot()->getWord() <= endWord){
        if(this->getLeft() != NULL){
            this->getLeft()->rangeSearch(startWord, endWord);
        }
        cout << this->getRoot()->getWord() << endl;
        if(this->getRight() != NULL){
            this->getRight()->rangeSearch(startWord, endWord);
        }
    }
    else if(this->getRoot()->getWord() < startWord){
        if(this->getRight() != NULL){
            this->getRight()->rangeSearch(startWord, endWord);
        }
    }
    else if(this->getRoot()->getWord() > endWord){
        if(this->getLeft() != NULL){
            this->getLeft()->rangeSearch(startWord, endWord);
        }
    }
}


