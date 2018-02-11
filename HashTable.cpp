//
//  HashTable.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "HashTable.hpp"
#include "Node.hpp"
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

HashTable::HashTable(int dataSize){
    size = 3*dataSize / 2;
    count = 0;
    largestSearchTraversal = 0;
    hashArray = new Node[size];
    countArray = new bool[size];
    emptyAt = new bool[size];
    for (int i = 0; i<size; i++){
        onceOccupiedAt[i] = false;
        emptyAt[i] = true;
    }
}

HashTable::~HashTable(){
    delete [] hashArray;
}

bool HashTable::searchWord(string word){

    return false;
}

bool HashTable::insertWord(string word){
    int traversal = 0;
    Node node = Node(word);
    if( count > (size*2/3))
        return false;
    int index = hashWord1(word);
    if (emptyAt[index]){
        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        emptyAt[index] = false;
        count ++;
        cout << "Count of items in Hash Table: "<< count << endl;
        return true;
    }
    else{
        
        cout << "Collision happened" << endl;
        while(!emptyAt[index]){
            if (hashArray[index].getWord() == node.getWord()){
                hashArray[index].incrementCount();
                cout << "Count of " << word << " incremented. Count: "<< hashArray[index].getCount() << endl;
                return false;
                
            }
            int offset = hashWord2(word);
            traversal++;
            index = (index + offset * traversal) % size;
        }
        if (traversal > largestSearchTraversal){
            largestSearchTraversal = traversal;
        }

        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        emptyAt[index] = false;
        count++;
        cout << "Count of items in Hash Table: "<< count << endl;
        cout << "Largest Travesal: "<<largestSearchTraversal << endl;
        return true;
    }
}

bool HashTable::deleteWord(string word){
    return false;
}

int HashTable::hashWord1(string word){
    cout << "Hash 1:"<< endl;
    int stringLength = word.length(); 
    int index;
    unsigned int sum = 0;
    char wordArr[stringLength + 1];
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    cout << "Word: "<<word << endl;
    strcpy(wordArr, word.c_str());
    for (int i = 0; i< stringLength; i++){
        sum = sum + i*pow((int)(wordArr[i]), i);
        
    }
    index = sum % (size-1);
    cout << "Index: " << index << endl; 
    return index;
}

int HashTable::hashWord2(string word){
    cout << "Hash 2:"<< endl;
    int stringLength = word.length(); 
    int index;
    unsigned int sum = 0;
    char wordArr[stringLength + 1];
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    cout << "Word: "<<word << endl;
    strcpy(wordArr, word.c_str());
    for (int i = 0; i< stringLength; i++){
        sum = sum + (stringLength-1)*pow((int)(wordArr[i]), (stringLength-1)-i);
    }
    index = 1 + sum/size %(size-1);
    cout << "Index: " << index << endl; 
    return index;
}

void HashTable::sortWords(){
    
}

void HashTable::rangeSearch(string word1, string word2){

}
