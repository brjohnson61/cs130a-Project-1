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



using namespace std;


class Node {

private:
    string word;
    int count;
  

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
    
};
#endif /* Node_hpp */