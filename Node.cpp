//
//  Node.cpp
//  130a Project 1
//
//  Created by Blake Johnson on 1/31/18.
//
//

#include "Node.hpp"
#include <string>

using namespace std;

class Node {
    
public:
    Node();
    Node(int count);
    Node(String word);
    Node(String word, int count)
    String getWord(void);
    int getCount(void);
    int getWordLength(void);
    String printNode(void);
    
private:
    String word;
    int count
};
