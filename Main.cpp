#include <stdio.h>
#include <string>
#include <iostream>
#include "Node.hpp"
#include "HashTable.hpp"

using namespace std;

int main(){

string input = "Matty Does Not FUCK";
int number = 10;


// while(input != "exit"){
//     cout << "input node word or 'exit' to quit: " << endl;
//     cin >> input;
//     cout << "input count: " << endl;
//     cin >> number;

//     cout << "input: " << input << endl;
//     cout << "count: " << number << endl;

    Node* temp = new Node(input, number);
    Node* temp1 = new Node(input + "1");
    Node* temp2 = new Node();

    cout << "Node 0: ";
    (*temp).printNode();
    cout << "Updating count to 18" << endl;
    temp->setCount(18);
    (*temp).printNode();
    cout << "Node 1: ";
    (*temp1).printNode();
    cout << endl;
    cout << "Node 2: ";
    (*temp2).printNode();
    cout << endl;


    // Hash Table Testing
    HashTable table1 = HashTable(100);
    int letter = table1.hashWord("letter");
    int increment = table1.hashWord("increment");
    int character = table1.hashWord("character");
    int fernando = table1.hashWord("fernando");
    int Fernando = table1.hashWord("FerNando");

    cout << "Letter: " << letter<< endl;
    cout << "increment : " << increment<< endl;
    cout << "fernando : " << fernando << endl;
    cout << "Fernando : " << Fernando << endl;
    // END Hash Table Testing


    return 0;
}