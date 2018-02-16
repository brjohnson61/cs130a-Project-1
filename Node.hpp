
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
    Node( string word);
    Node(string word, int count);
    Node(Node* other); 
    
    string getWord(void);
    int getCount(void);
    int getWordLength(void);
    void printNode(void);
    void setWord(string word);
    void setCount(int count);
    void incrementCount(void);
    void decrementCount(void);
    bool operator==( Node& rhs);
    bool operator<( Node& rhs);
    bool operator>( Node& rhs);

    
};

void outputToFile(string word, string pathName);

#endif /* Node_hpp */