//
//  Node.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "Node.hpp"
#include <string>
#include <iostream>

using namespace std;

//Default Constructor
Node::Node(){
    word = "";
    count = 0;
    this.right = NULL;
    this.left = NULL;
}

//String-only constructor
Node::Node(const string word){
    this->word = word;
    count = 1;
    this.right = NULL;
    this.left = NULL;
}

//String and Count constructor
Node::Node(const string word, const int count){
    this->word = word;
    this->count = count;
    this.right = NULL;
    this.left = NULL;
}

//Destructor
Node::~Node(){
    this.right = NULL;
    this.left = NULL;
}

//Getter for the node's word
string Node::getWord(){
    return this->word;
}

//Getter for the node's count
int Node::getCount(){
    return this->count;
}

//Getter for the node's word length
int Node::getWordLength(){
    return this->word.length;
}

//Prints the word-count pair of a node
string Node::printNode(){
    cout << "Word: " << this->word << " Count: " << to_string(this->count) << endl;
}

//Setter for the node's word
void Node::setWord(string word){
    this->word = word;
}

//Setter for the word's count
void Node::setCount(int count){
    this->count = count;
}

//Increases the node's count by 1
void Node::incrementCount(){
    this->count++;
}

//Decreases the node's count by 1
void Node::decrementCount(){
    this->count--;
}

//Sets the right node
void Node::setRight(const Node &right){
    this.right = right;
}

//Sets the left node
void Node::setLeft(const Node &left){
    this.left = left;
}

//Delete right pointer and all of its right pointers
bool deleteRight(void){
    if(this.right != null){
        (*(this.right)).deleteRight();
        delete this;
        return true;
    }
    else{
        return false;
    }
}

//Delete left pointer and all of its left pointers
bool deleteLeft(void){
    if(this.left != null){
        (*(this.left)).deleteLeft();
        delete this;
        return true;
    }
    else{
        return false;
    }
}


