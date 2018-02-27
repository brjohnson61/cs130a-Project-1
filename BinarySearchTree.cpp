//
//  BinarySearchTree.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//


#include <string>
#include <stdio.h>
#include <iostream>
#include "BinarySearchTree.hpp"


using namespace std;


BinarySearchTree::BinarySearchTree(BinarySearchTree* tree){
    if(tree->getRoot() != NULL){
        this->root = new Node(tree->getRoot());
        if(tree->getRight() != NULL){
            this->right = new BinarySearchTree(tree->getRight());
        }
        else{
            this->right = NULL;
        }
        if(tree->getLeft() != NULL){
            this->left = new BinarySearchTree(tree->getLeft());
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

BinarySearchTree::BinarySearchTree(){
    this->right = NULL;
    this->left = NULL;
    this->root = NULL;
}

BinarySearchTree::BinarySearchTree(Node* root1){
    this->right = NULL;
    this->left = NULL;
    if(root1 == NULL){
        this->root = NULL;
    }
    else{
        this->root = new Node(root1);
    }
}

Node* BinarySearchTree::getRoot(){
    return this->root;
}

BinarySearchTree* BinarySearchTree::getLeft(){
    return this->left;
}

BinarySearchTree* BinarySearchTree::getRight(){
    return this->right;
}

BinarySearchTree* BinarySearchTree::minimumRoot(){
    if(this->left == NULL){
        return this;
    }
    else{
        return this->left->minimumRoot();
    }
}

void BinarySearchTree::setRoot(Node* root){
    this->root = root;
}

void BinarySearchTree::insertNode(string word){
    if(this->root == NULL){
        this->root = new Node(word);
    }
    else{
        if(this->root->getWord() == word){
            this->root->increaseCount();
        }
        else if(this->root->getWord() < word){
            if(this->right == NULL){
                this->right = new BinarySearchTree();
            }
            this->right->insertNode(word);
        }
        else{
            if(this->left == NULL){
                this->left = new BinarySearchTree();
            }
            this->left->insertNode(word);
        }
    }
}

BinarySearchTree* BinarySearchTree::deleteNode(string word){
    if(this->root == NULL){
        return this;
    }
    
    if(this->root->getWord() == word){
        if(this->root->getCount() > 1){
            this->root->decreaseCount();
            return this;
        }
        if(this->right==NULL && this->left==NULL){
                delete this;
                return NULL;
        }
        else if((this->getRight() == NULL) != (this->left == NULL)){
            BinarySearchTree* temp;
            if(this->right==NULL){
                temp = this->left;
                this->left = NULL;
            }
            else{
                temp = this->right;
                this->right = NULL;
            }
            delete this;
            return temp;
        }
        else{
            BinarySearchTree* temp = this->right->minimumRoot();
            
            this->root->setWord(temp->getRoot()->getWord());
            this->root->setCount(temp->getRoot()->getCount());

            this->right = this->right->deleteNode(this->root->getWord());
            return this;
        }
    }
    else if(this->root->getWord() < word){
        if(this->right == NULL){
            return this;
        }
        else{
            this->right = this->right->deleteNode(word);
            return this;
        }
    }
    else{
        if(this->left == NULL){
            return this;
        }
        else{
            this->left = this->left->deleteNode(word);
            return this;
        }
    } 
}

bool BinarySearchTree::searchTree(string word){
    if(this->root == NULL){
        return false;
    }
    else{
        if(this->root->getWord() == word){
            return true;
        }
        else if(this->root->getWord() < word){
            if(this->right == NULL){
                return false;
            }
            else{
                return this->right->searchTree(word);
            }
        }
        else{
            if(this->left == NULL){
                return false;
            }
            else{
                return this->left->searchTree(word);
            }
        }
    }
}


void BinarySearchTree::sortTree(){
    if(this != NULL){
        if(this->root != NULL)
            this->left->sortTree();
            outputToFile(this->root->getWord(), "output.txt");
            this->right->sortTree();
    }
}

void BinarySearchTree::rangeSearchTree(string begin, string end){
    if(this->root->getWord() >= begin && this->root->getWord() <= end){
        if(this->left != NULL){
            this->left->rangeSearchTree(begin, end);
        }
        cout << this->root->getWord() << endl;
        if(this->right != NULL){
            this->right->rangeSearchTree(begin, end);
        }
    }
    else if(this->root->getWord() < begin){
        if(this->right != NULL){
            this->right->rangeSearchTree(begin, end);
        }
    }
    else if(this->root->getWord() > end){
        if(this->left != NULL){
            this->left->rangeSearchTree(begin, end);
        }
    }
}
