//
//  Node.hpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>

#endif /* Node_hpp */

using namespace std;


class Node {

private:
    string word;
    int count;
    Node *right;
    Node *left;

public:
    Node();
    Node(const string word);
    Node(const string word, const int count);
    Node(Node* other);
    ~Node();
    
    string getWord(void);
    int getCount(void);
    int getWordLength(void);
    void printNode(void);
    void setWord(string word);
    void setCount(int count);
    void incrementCount(void);
    void decrementCount(void);
    void setRight(Node* right);
    void setLeft(Node* left);
    Node* getRight(void);
    Node* getLeft(void);
    bool deleteRight(void);
    bool deleteLeft(void);
    bool rightIsNull(void);
    bool leftIsNull(void);
};
