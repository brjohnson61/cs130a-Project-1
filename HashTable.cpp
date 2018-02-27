//
//  HashTable.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "HashTable.hpp"
#include "Node.hpp"
#include "BinarySearchTree.hpp"
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

HashTable::HashTable(int capacity){
    size = (3*capacity)/2;
    largestInsertTraversal = 0;
    hashArr = new Node[size];
    onceOccupiedAt = new bool[size];
    count = 0;
    isEmptyAt = new bool[size];
    for (int i = 0; i<size; i++){
        onceOccupiedAt[i] = false;
        isEmptyAt[i] = true;
    }
}

HashTable::~HashTable(){
    delete [] hashArr;
    delete [] onceOccupiedAt;
    delete [] isEmptyAt;
}

int HashTable::searchTable(string word){
    int index = hashFunction(word);
    int traversal = 0;
    
    while (onceOccupiedAt[index]){
        if (traversal > largestInsertTraversal){
            return -1;
        }
        if (!isEmptyAt[index]){
            if (hashArr[index].getWord() == word){
                return index;
            }
        }
            traversal++;
            index = (index + 1) % size;
    }
    return -1;
}

bool HashTable::insertNode(string word){
    
    int traversal = 0;
    Node node = Node(word);

    if( count > (size*2/3)){
        return false;
    }

    int index = hashFunction(word);

    if (isEmptyAt[index]){
        hashArr[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count ++;
        return true;
    }
    else{
        while(!isEmptyAt[index]){
            int tempIndex = 0;
            if (hashArr[index].getWord() == node.getWord()){
                hashArr[index].increaseCount();
                return true;
            }

            traversal++;
            index = (index + 1 ) % size;
        }
       
        hashArr[index] = node;
        onceOccupiedAt[index] = true;
        isEmptyAt[index] = false;
        count++;

        if(traversal > largestInsertTraversal){
            largestInsertTraversal = traversal;
        }
        return true;
    }
}

bool HashTable::deleteNode(string word){
    int index = searchTable(word);
    if (index < 0){
        return false;
    }
    isEmptyAt[index] = true;
    count --;
    return true;
}

void HashTable::sortTable(){
    Node* tempHashArray = new Node [count];
    int tempCount = 0;
    for (int i = 0; i < size; i ++ ){
        if (!isEmptyAt[i]){
            tempHashArray[tempCount] = hashArr[i];
            tempCount++;
        }
    }

    mergeSort(tempHashArray, 0, count-1);
    
    for(int i = 0; i < count; i ++){
        outputToFile(tempHashArray[i].getWord(), "output.txt");
    }
}

void HashTable::rangeSearchTable(string word1, string word2){
    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    
    for (int i = 0; i < size; i ++){
        if(!isEmptyAt[i]){
            if ((hashArr[i].getWord() >= word1) && (hashArr[i].getWord() <= word2)){
                cout << hashArr[i].getWord() << endl;
            }
        }
    }  
}

void HashTable::printHashTable(){
    int itemsFound = 0;
    for (int i = 0; i < size ; i ++ ){
        if (!isEmptyAt[i]){
            cout << i << " : " << hashArr[i].getWord() << endl;
        }
    }
}

int HashTable::hashFunction(string word){
    int wordSize = word.length();
    char wordArr[wordSize + 1]; 
    strcpy(wordArr, word.c_str());
    unsigned int total = 0;
    int hashInd;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for (int i = 0; i< wordSize; i++){
        total += i*pow((int)(wordArr[i]), i);
    }
    hashInd = total % (size-1);
    return hashInd;
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
    Node tempNode = Node(word);
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
            return leftIndex;
        }
    }if(leftIndex > rightIndex){
        return leftIndex;
    }
}