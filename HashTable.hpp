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

    bool searchWord(string word);
    bool insertWord(string word);
    bool deleteWord(string word);
    void sortWords(void);
    void rangeSearch(string word1, string word2);
    int hashWord1(string word);
    int hashWord2(string word);
    


private:
    int size;
    Node *hashArray;
    bool *countArray;
    bool *emptyAt;
    int count;
    int largestSearchTraversal;
    

};
#endif /* HashTable_hpp */