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
    
  
     
    table1.insertWord("adam");
    cout << endl ;
    cout << endl;
    table1.insertWord("blake");
    cout << endl ;
    cout << endl;
    table1.insertWord("matty");
    cout << endl ;
    cout << endl;
    table1.insertWord("fernando") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("grant");
    cout << endl ;
    cout << endl;
    table1.insertWord("ricky");
    cout << endl ;
    cout << endl;
    table1.insertWord("komei");
    cout << endl ;
    cout << endl;
    table1.insertWord("min") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("seiji");
    cout << endl ;
    cout << endl;
    table1.insertWord("caleb");
    cout << endl ;
    cout << endl;
    table1.insertWord("pasado");
    cout << endl ;
    cout << endl;
    table1.insertWord("goleta") ;
    cout << endl ;
    cout << endl;

    table1.insertWord("pilot");
    cout << endl ;
    cout << endl;
    table1.insertWord("airplane");
    cout << endl ;
    cout << endl;
    table1.insertWord("houses");
    cout << endl ;
    cout << endl;
    table1.insertWord("animals") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("animals");
    cout << endl ;
    cout << endl;
    table1.insertWord("doctors");
    cout << endl ;
    cout << endl;
    table1.insertWord("trees");
    cout << endl ;
    cout << endl;
    table1.insertWord("traversal") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("delplaya");
    cout << endl ;
    cout << endl;
    table1.insertWord("trigo");
    cout << endl ;
    cout << endl;
    table1.insertWord("sabado");
    cout << endl ;
    cout << endl;
    table1.insertWord("goleta") ;
    cout << endl ;
    cout << endl;

    table1.insertWord("human");
    cout << endl ;
    cout << endl;
    table1.insertWord("tiger");
    cout << endl ;
    cout << endl;
    table1.insertWord("elephant");
    cout << endl ;
    cout << endl;
    table1.insertWord("cat") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("dog");
    cout << endl ;
    cout << endl;
    table1.insertWord("snake");
    cout << endl ;
    cout << endl;
    table1.insertWord("chimpanzee");
    cout << endl ;
    cout << endl;
    table1.insertWord("newyork") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("losbanos");
    cout << endl ;
    cout << endl;
    table1.insertWord("losangeles");
    cout << endl ;
    cout << endl;
    table1.insertWord("palmdale");
    cout << endl ;
    cout << endl;
    table1.insertWord("goleta") ;
    cout << endl ;
    cout << endl;

    table1.insertWord("toyota");
    cout << endl ;
    cout << endl;
    table1.insertWord("ford");
    cout << endl ;
    cout << endl;
    table1.insertWord("chevrolet");
    cout << endl ;
    cout << endl;
    table1.insertWord("honda") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("hundai");
    cout << endl ;
    cout << endl;
    table1.insertWord("tires");
    cout << endl ;
    cout << endl;
    table1.insertWord("axle");
    cout << endl ;
    cout << endl;
    table1.insertWord("believe") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("achieve");
    cout << endl ;
    cout << endl;
    table1.insertWord("inspired");
    cout << endl ;
    cout << endl;
    table1.insertWord("introduced");
    cout << endl ;
    cout << endl;
    table1.insertWord("apreciate") ;
    cout << endl ;
    cout << endl;

    table1.insertWord("jews");
    cout << endl ;
    cout << endl;
    table1.insertWord("catholic");
    cout << endl ;
    cout << endl;
    table1.insertWord("christian");
    cout << endl ;
    cout << endl;
    table1.insertWord("indian") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("budhism");
    cout << endl ;
    cout << endl;
    table1.insertWord("action");
    cout << endl ;
    cout << endl;
    table1.insertWord("jumping");
    cout << endl ;
    cout << endl;
    table1.insertWord("instigating") ;
    cout << endl ;
    cout << endl;
    table1.insertWord("afordable");
    cout << endl ;
    cout << endl;
    table1.insertWord("expensive");
    cout << endl ;
    cout << endl;
    table1.insertWord("lowlofe");
    cout << endl ;
    cout << endl;
    table1.insertWord("chill") ;
    cout << endl ;
    cout << endl;
    // END Hash Table Testing


    return 0;
}
