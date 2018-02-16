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
    mergeSort(tempHashArray, 0, count-1);
    

    for(int i = 0; i < count; i ++){
        outputToFile(tempHashArray[i].getWord(), "hashOutput.txt");
    }

}

void HashTable::rangeSearch(string word1, string word2){
    Node* tempHashArray = new Node [count];
    int tempCount = 0;
    for (int i = 0; i < size; i ++ ){
        if (!isEmptyAt[i]){
            tempHashArray[tempCount] = hashArray[i];
            tempCount++;
        }
    }
    mergeSort(tempHashArray, 0, count-1);

    int index1 = binarySearch(tempHashArray,0, count-1,word1);
    Node node1 = Node(word1,1);
    Node node2 = Node (word2,1);
    int index2 = binarySearch(tempHashArray,0, count-1,word2);
    cout << "Index 1: " << index1 << endl;
    cout << "Index 2: " << index2 << endl;

    if (index1 < index2){
        while ((tempHashArray[index1] < node1 )&& (index1 < count)){
            index1 = index1 + 1;
        }
        while ((tempHashArray[index2] > node2) && (index2 < count)){
            index2 = index2 - 1;
        }
        for (int i = index1; i < index2+1; i++){
            tempHashArray[i].printNode();
        }
    }else if (index1 > index2){
        while ((tempHashArray[index2] < node2 )&& (index2 < count)){
            index2 = index2 + 1;
        }
        while ((tempHashArray[index1] > node1) && (index1 < count)){
            index1 = index1 - 1;
        }
        for (int i = index2; i < index1+1; i++){
            tempHashArray[i].printNode();
        }
    }else {
        tempHashArray[index1].printNode();
    }

    
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
        if ((ar1[i] < ar2[j]) || (ar1[i] == ar2[j])){ 
            array[k] = ar1[i];
            i++;
            k++;
        }else{
            array[k] = ar2[j];
            j++;
            k++;
        }
    }
    while (i < ar1Length){
        array[k] = ar1[i];
        i++;
        k++;
    }

    while (j < ar2Length){
        array[k] = ar2[j];
        j++;
        k++;
    }

}

void mergeSort(Node array[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex){
        int middle = (leftIndex+(rightIndex))/2;

        mergeSort(array, leftIndex, middle);
        mergeSort(array, middle+1, rightIndex);

        merge(array, leftIndex, middle , rightIndex);
    }

}

int binarySearch(Node array[], int leftIndex, int rightIndex, string word){
    Node tempNode = Node(word,1);
    if (leftIndex < rightIndex){
        int middle = (leftIndex + rightIndex)/2;
        if (array[middle] < tempNode){
            return binarySearch(array, middle +1, rightIndex, word);
        }else if (array[middle] > tempNode){
            return binarySearch(array, leftIndex, middle-1, word);
        }else {
            return middle;
        }
    } else if (leftIndex == rightIndex){
        if (array[leftIndex] == tempNode)
            return leftIndex;
        else {
            cout << "No word found" << endl;
            return leftIndex;
        }
    }if(leftIndex > rightIndex){
        return leftIndex;
    }
}