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

Node::Node(){
    word = "";
    count = 0;
}

Node::Node(string word){
    this->word = word;
    count = 1;
}

Node::Node(string word, int count){
    this->word = word;
    this->count = count;
}

Node::~Node(){
    
}

string Node::getWord(){
    return this->word;
}

int Node::getCount(){
    return this->count;
}

int Node::getWordLength(){
    return this->word.length;
}

string Node::printNode(){
    cout << "Word: " << this->word << " Count: " << to_string(this->count) << endl;
}

void Node::setWord(string word){
    this->word = word;
}

void Node::setCount(int count){
    this->count = count;
}


void Node::incrementCount(){
    this->count++;
}

void Node::decrementCount(){
    this->count--;
}
