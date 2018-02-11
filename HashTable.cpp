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
    largestInsertTraversal = 0;
    hashArray = new Node[size];
    onceOccupiedAt = new bool[size];
    isEmptyAt = new bool[size];
    for (int i = 0; i<size; i++){
        onceOccupiedAt[i] = false;
        isEmptyAt[i] = true;
    }
}

HashTable::~HashTable(){
    delete [] hashArray;
}

bool HashTable::searchWord(string word){
    int index = hashWord1(word);
    int traversal = 0;
    if (hashArray[index].getWord() == word)
        return true;
    int offset = hashWord2(word);

    while (onceOccupiedAt[index]){
        if (traversal > largestInsertTraversal)
            return false;
        if (isEmptyAt[index]){
            traversal ++;
            index = (index + offset * traversal) % size;
        }else {
            if (hashArray[index].getWord() == word){
                return true;
            }

            traversal++;
            index = (index + offset * traversal) % size;
        }
    }
    return false;
}

bool HashTable::insertWord(string word){
    int traversal = 0;
    Node node = Node(word);
    if( count > (size*2/3))
        return false;
    int index = hashWord1(word);
    if (isEmptyAt[index]){
        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count ++;
        cout << "Entered " << word << "at index: " << index<< endl;
        cout << "Traversal: " << traversal;
        cout << "Count of items in Hash Table: "<< count << endl;
        return true;
    }
    else{

        int offset = hashWord2(word);
        cout << "Offset: "<< offset << endl;
        while(!isEmptyAt[index]){
            cout << "Collision happened at index: " << index <<  endl;
            if (hashArray[index].getWord() == node.getWord()){
                hashArray[index].incrementCount();
                cout << "Count of " << word << " incremented. Count: "<< hashArray[index].getCount() << endl;
                return false;
                
            }
            
            traversal++;
            index = (index + offset * traversal) % size;
        }
        if (traversal > largestInsertTraversal){
            largestInsertTraversal = traversal;
        }

        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count++;
        cout << "At Index: "<< index << endl;
        cout << "Count of items in Hash Table: "<< count << endl;
        cout << "Largest Travesal: "<<largestInsertTraversal << endl;
        return true;
    }
}

bool HashTable::deleteWord(string word){
    return false;
}

int HashTable::hashWord1(string word){
    int stringLength = word.length(); 
    int index;
    unsigned int sum = 0;
    char wordArr[stringLength + 1];
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    strcpy(wordArr, word.c_str());
    for (int i = 0; i< stringLength; i++){
        sum = sum + i*pow((int)(wordArr[i]), i);
        
    }
    index = sum % (size-1);
    return index;
}

int HashTable::hashWord2(string word){
    int stringLength = word.length(); 
    int index;
    unsigned int sum = 0;
    char wordArr[stringLength + 1];
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    strcpy(wordArr, word.c_str());
    for (int i = 0; i< stringLength; i++){
        sum = sum + (stringLength-1)*pow((int)(wordArr[i]), (stringLength-1)-i);
    }
    index = 1 + sum/size %(size-1);
    return index;
}

void HashTable::sortWords(){
    
}

void HashTable::rangeSearch(string word1, string word2){

}
