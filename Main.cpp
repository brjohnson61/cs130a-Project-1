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
    int letter = table1.hashWord1("letter");
    int increment = table1.hashWord1("increment");
    int character = table1.hashWord1("character");
    int fernando = table1.hashWord1("fernando");
    int Fernando = table1.hashWord1("FerNando");

    int letter1 = table1.hashWord2("letter");
    int increment1 = table1.hashWord2("increment");
    int character1 = table1.hashWord2("character");
    int fernando1 = table1.hashWord2("fernando");
    int Fernando1 = table1.hashWord2("FerNando");

    cout << "Letter: " << letter<< endl;
    cout << "increment : " << increment<< endl;
    cout << "fernando : " << fernando << endl;
    cout << "Fernando : " << Fernando << endl;

    cout << "Letter1: " << letter1<< endl;
    cout << "increment1 : " << increment1<< endl;
    cout << "fernando1 : " << fernando1 << endl;
    cout << "Fernando1 : " << Fernando1 << endl;
    // END Hash Table Testing


    return 0;
}