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
    HashTable(int capacity);
    ~HashTable();
    int hashFunction(string word);
    int searchTable(string word);
    void rangeSearchTable(string word1, string word2);
    bool insertNode(string word);
    bool deleteNode(string word);
    void sortTable(void);
    void printHashTable(void);

private:
    int size;
    Node *hashArr;
    bool *onceOccupiedAt;
    bool *isEmptyAt;
    int count;
    int largestInsertTraversal;
};

void mergeSort(Node array[], int leftIndex, int rightIndex);
void merge(Node array[], int leftIndex, int middle, int rightIndex);
int binarySearch(Node array[], int leftIndex, int rightIndex, string word);

#endif /* HashTable_hpp */

