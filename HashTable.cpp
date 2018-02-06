//
//  HashTable.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "HashTable.hpp"
#include <string>
#include <math.h>
#include <iostream>

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
    int stringLength = word.length(); 
    int index;
    unsigned int sum = 0;
    for (int i = 0; i< stringLength; i++){
        sum = sum + i*pow((int)word.charAt(i), i);
        cout << sum << endl;
    }
    index = sum % (size);
    return index;
}

void HashTable::sortWords(){
    
}

void HashTable::rangeSearch(string word1, string word2){

}