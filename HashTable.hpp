//
//  HashTable.hpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include <string>
#include<stdio.h>
#include"Node.hpp"




using namespace std;

class HashTable {
public:
    HashTable(int dataSize);
    ~HashTable();

    int searchWord(string word);
    bool insertWord(string word);
    bool deleteWord(string word);
    void sortWords(void);
    void rangeSearch(string word1, string word2);
    int hashFunction(string word);
    void printHashTable(void);
    


private:
    int size;
    Node *hashArray;
    bool *onceOccupiedAt;
    bool *isEmptyAt;
    int count;
    int largestInsertTraversal;
    

};

void mergeSort(Node array[], int leftIndex, int rightIndex);
void merge(Node array[], int leftIndex, int middle, int rightIndex);
int binarySearch(Node array[], int leftIndex, int rightIndex, string word);

#endif /* HashTable_hpp */

