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
    delete [] onceOccupiedAt;
    delete [] isEmptyAt;
}

bool HashTable::searchWord(string word){
    int index = hashWord1(word);
    cout << "Index: "<< index << endl;
    int traversal = 0;
    int offset = hashWord2(word);

    while (onceOccupiedAt[index]){
        if (traversal > largestInsertTraversal){
            cout << "Exceeded largest insert traversal; Item is not in the array"<< endl;
            return false;
        }
        if (isEmptyAt[index]){
            cout << "Is empty at index" << endl;
            traversal ++;
            index = (((index + offset)%size) * traversal) % size;
        }else {
            if (hashArray[index].getWord() == word){
                cout << "Item found at index: " << index << endl;
                cout << "Traversal:" << traversal << endl;
                return true;
                
            }

            traversal++;
            index = (((index + offset)%size) * traversal) % size;
            cout << "Next index: " << index << endl;
        }
    }
    cout << "Word is not in the array" << endl;
    return false;
}

bool HashTable::insertWord(string word){
    
    int traversal = 0;
    Node node = Node(word);

    if( count > (size*2/3))
        return false;
    cout << "Inserting word: " << word << endl;
    int index = hashWord1(word);

    if (isEmptyAt[index]){
        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count ++;
        cout << "Inserted " << word << " at index: " << index<< endl;
        cout << "Traversal: " << traversal << endl;
        cout << "Count: "<< count << endl;
        return true;
    }
    else{

        int offset = hashWord2(word);
        cout << "Offset: "<< offset << endl;
        while(!isEmptyAt[index]){
            cout << "Collision happened at index: " << index <<  endl;
            if (hashArray[index].getWord() == node.getWord()){
                hashArray[index].incrementCount();
                cout << "Count of " << word << " incremented. Count  of word: "<< hashArray[index].getCount() << endl;
                cout << "Traversal: " << traversal << endl;
                cout << "Count: " << count << endl;
                return true;
                
            }
            
            traversal++;
            index = (((index + offset)%size) * traversal) % size;
            cout << "Traversal: "<< traversal << endl;
        }
       
        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count++;
        cout << "Inserted word "<< word << " at index: "<< index << endl;
        cout << "Traversal: "<< traversal << endl;;
        cout << "Count: "<< count << endl;

         if (traversal > largestInsertTraversal){
            largestInsertTraversal = traversal;
            cout << "LargestInsertTravesal changed to :" << largestInsertTraversal << endl;
        }

        return true;
    }
}

bool HashTable::deleteWord(string word){
    cout << "Deleting word: " << word << endl;
    int index = hashWord1(word);
    int offset = hashWord2(word);
    int traversal = 0;

    while (onceOccupiedAt[index]){
        if (traversal > largestInsertTraversal){
            return false;
        }
        if (isEmptyAt[index]){
            cout << "Empty at index: " << index << endl;
            traversal ++;
            index = (((index + offset)%size) * traversal) % size;
        }else {
            if (hashArray[index].getWord() == word){
                if (hashArray[index].getCount() < 2){
                    isEmptyAt[index] = true;
                    cout << "Sucessfully deleted word" << endl;
                    return true;
                }else{
                    cout << "Word had count greater than 1" << endl;
                    hashArray[index].decrementCount();
                    cout << "Word count changed to " << hashArray[index].getCount() << endl;
                    return true;
                }
                
            }

            traversal++;
            index = (((index + offset)%size) * traversal) % size;
        }
    }
    cout << "Word is not in the array" << endl;
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
