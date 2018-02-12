//
//  HashTable.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "HashTable.hpp"
#include "Node.hpp"
#include "BST.hpp"
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

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
    delete [] onceOccupiedAt;
    delete [] isEmptyAt;
}

int HashTable::searchWord(string word){
    int index = hashFunction1(word);
    int traversal = 0;
    int offset = hashFunction2(word);

    while (onceOccupiedAt[index]){
        if (traversal > largestInsertTraversal){
            return -1;
        }
        if (!isEmptyAt[index]){
            if (hashArray[index].getWord() == word){
                return index;
            }
        }
            traversal++;
            index = (((index + offset)%size) * traversal) % size;
    }
    return -1;
}

bool HashTable::insertWord(string word){
    
    int traversal = 0;
    Node node = Node(word);

    if( count > (size*2/3))
        return false;
    int index = hashFunction1(word);

    if (isEmptyAt[index]){
        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count ++;
        return true;
    }
    else{

        int offset = hashFunction2(word);
        while(!isEmptyAt[index]){
            if (hashArray[index].getWord() == node.getWord()){
                hashArray[index].incrementCount();
                return true;
            }
            
            traversal++;
            index = (((index + offset)%size) * traversal) % size;
        }
       
        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count++;

         if (traversal > largestInsertTraversal){
            largestInsertTraversal = traversal;
        }

        return true;
    }
}

bool HashTable::deleteWord(string word){
    int index = searchWord(word);
    if (index < 0){
        return false;
    }
    isEmptyAt[index] = true;
    return true;
}

int HashTable::hashFunction1(string word){
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

int HashTable::hashFunction2(string word){
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
    int itemsFound = 0;
    BST* tempSortTree = new BST();

    for (int i = 0; i < size; i ++){
        if (itemsFound > count){
            continue;
        }
        if (!isEmptyAt[i]){
            tempSortTree->insert(&hashArray[i]);
        }
    }
    tempSortTree->sort();
}

void HashTable::rangeSearch(string word1, string word2){
    int itemsFound = 0;
    BST* tempSortTree = new BST();

    for (int i = 0; i < size; i ++){
        if (itemsFound > count){
            continue;
        }
        if (!isEmptyAt[i]){
            tempSortTree->insert(&hashArray[i]);
        }
    }
    tempSortTree->rangeSearch(word1, word2);
}
