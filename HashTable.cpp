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
    int index = hashFunction(word);
    int traversal = 0;
    

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
            index = (index + 1) % size;
    }
    return -1;
}

bool HashTable::insertWord(string word){
    
    int traversal = 0;
    Node node = Node(word);

    if( count > (size*2/3))
        return false;
    int index = hashFunction(word);

    if (isEmptyAt[index]){
        hashArray[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count ++;
        return true;
    }
    else{

        while(!isEmptyAt[index]){
            int tempIndex = 0;
            if (hashArray[index].getWord() == node.getWord()){
                hashArray[index].incrementCount();
                return true;
            }

            traversal++;
            index = (index + 1 ) % size;
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
    count --;
    return true;
}

int HashTable::hashFunction(string word){
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


void HashTable::sortWords(){
    Node* tempHashArray = new Node [count];
    int tempCount = 0;
    for (int i = 0; i < size; i ++ ){
        if (!isEmptyAt[i]){
            tempHashArray[tempCount] = hashArray[i];
            tempCount++;
        }
    }
    cout << "Before Merge" << endl;
    mergeSort(tempHashArray, 0, size -1);
    cout << "AfterMerge"<< endl;

    for(int i = 0; i < count; i ++){
        tempHashArray[i].printNode();
    }

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



void HashTable::printHashTable(){
    int itemsFound = 0;
    for (int i = 0; i < size ; i ++ ){
        if (!isEmptyAt[i]){
            cout << i << " : " << hashArray[i].getWord() << endl;
        }
    }
}


void merge(Node array[], int leftIndex, int middle, int rightIndex){
    cout << "Merge" << endl;
    int i, j,k;
    int ar1Length = middle - leftIndex+ 1;
    int ar2Length = rightIndex - middle;
    
    Node ar1[ar1Length];
    Node ar2[ar2Length];

    for (int i = 0; i < ar1Length ; i ++){
        ar1[i] = array[leftIndex+i];
    }
    for (int j = 0; j < ar2Length; j++ ){
        ar2[j] = array[middle+j+1];
    }

    i = 0;
    j = 0; 
    k = leftIndex;
    while ( (i < ar1Length) && (j < ar2Length) ){
        cout << "In Merge While loop" << endl;
        if ((ar1[i] < ar2[j]) || (ar1[i] == ar2[j])){
            cout << "Item in array 1 is less than or equal to item in array 2 " << endl;
            cout << "WordA: "<< ar1[i].getWord() << endl;
            cout << "WordB: "<< ar2[j].getWord() << endl; 
            cout << "I: " << i << endl;
            cout << "J:" << j << endl;
            cout << "Ar1 Length: " << ar1Length << endl;
            cout << "Ar2 Length: " << ar2Length << endl; 
            array[k] = ar1[i];
            i++;
            k++;
        }else{
             cout << "Item in array 1 is greater than item in array 2 " << endl;
            array[k] = ar2[j];
            j++;
            k++;
        }
    }
    while (i < ar1Length){
        cout << "Finish first half of array, Index: "<< i << endl;
        cout << "array 1 length: " << ar1Length << endl;
        array[k] = ar1[i];
        i++;
        k++;
    }

    while (j < ar2Length){
        cout << "Finish second half of array, Index:" << j<<  endl;
        array[k] = ar2[j];
        j++;
        k++;
    }

}

void mergeSort(Node array[], int leftIndex, int rightIndex){
    cout << "MergeSort"<< endl;
    if (leftIndex < rightIndex){
        int middle = (leftIndex+rightIndex)/2;

        mergeSort(array, leftIndex, middle);
        mergeSort(array, middle+1, rightIndex);

        merge(array, leftIndex, middle , rightIndex);
    }

}