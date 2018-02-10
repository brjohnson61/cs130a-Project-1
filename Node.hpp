<<<<<<< HEAD
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
    
};
=======
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
>>>>>>> d8788e1c6d767ff4d90ae2f685cbce83dd2c4d64
#endif /* Node_hpp */