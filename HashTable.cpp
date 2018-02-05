//
//  HashTable.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "HashTable.hpp"
#include <string>

using namespace std;

HashTable::HashTable(int dataSize){
    size = 3*dataSize / 2;
    hashArray = new Node*[size];
    for (int i = 0; i<size; i++){
        hashArray[i] = NULL;
    }
}

HashTable::~HashTable(){
    delete [] hashArray;
}

bool HashTable::searchWord(string word){
    return false;
}

bool HashTable::insertWord(string word){
    return false;
}

bool HashTable::deleteWord(string word){
    return false;
}
int HashTable::hashWord(string word){
    return 0;
}