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
}

//String-only constructor
Node::Node(const string word){
    this->word = word;
    count = 1;
}

//String and Count constructor
Node::Node(const string word, const int count){
    this->word = word;
    this->count = count;
}

Node::Node(Node* other){
    this->word = other->getWord();
    this->count = other->getCount();
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
    return ((this->word).length());
}

//Prints the word-count pair of a node
void Node::printNode(){
    cout << "Word: " << this->word << " Count: " << this->count << endl;
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
