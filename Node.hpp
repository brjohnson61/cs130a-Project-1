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
    ~Node();
    
    string getWord(void);
    int getCount(void);
    int getWordLength(void);
    string printNode(void);
    void setWord(string word);
    void setCount(int count);
    void incrementCount(void);
    void decrementCount(void);
    void setRight(const Node &right);
    void setLeft(const Node &left);
    bool deleteRight(void);
    bool deleteLeft(void);
};
