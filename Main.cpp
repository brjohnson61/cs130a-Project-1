#include <stdio.h>
#include <string>
#include <iostream>
#include "Node.hpp"
#include "HashTable.hpp"
#include "BST.hpp"

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
    HashTable table1 = HashTable(20);
    
  
     
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

    bool fernandoSearch = table1.searchWord("fernando");
    cout << "Fernando Search: " << fernandoSearch << endl;
    cout << endl << endl;
    bool traversalSearch = table1.searchWord("traversal");
    cout << "Traversal Search: " << traversalSearch << endl;
    cout << endl << endl;
    bool grantSearch =  table1.searchWord("grant");
    cout << "Grant Search: " << grantSearch << endl; 
    cout << endl << endl;
   

    bool deletFernando = table1.deleteWord("fernando");
    cout << "Delete Fernando: " << deletFernando << endl;
    cout << endl << endl;
    bool deleteGrant  = table1.deleteWord("grant");
    cout << "Delete Grant: " << deleteGrant << endl;
    cout << endl << endl;


    bool fernandoSearch2 = table1.searchWord("fernando");
    cout << "Fernando Search 2: " << fernandoSearch2 << endl;
    cout << endl << endl;
    bool traversalSearch2 = table1.searchWord("traversal");
    cout << "Traversal Search 2: " << traversalSearch2 << endl;
    cout << endl << endl;
    bool grantSearch2 =  table1.searchWord("grant");
    cout << "Grant Search 2: " << grantSearch2 << endl; 
    cout << endl << endl;   

    



    // END Hash Table Testing
    cout << endl << endl;
    cout << "Begin Final Turnin Select Menu" << endl;

    BST* mainBST = new BST();
    (mainBST->getRoot() == NULL) ? cout << "NULL" : cout << "not NULL";
    cout << endl;

    while(1){
        int userMenuSelect;
        string firstArgString;
        string secondArgString;

        cout << "Option 1: Search" << endl;
        cout << "Option 2: Insert" << endl;
        cout << "Option 3: Delete" << endl;
        cout << "Option 4: Sort" << endl;
        cout << "Option 5: Range Search" << endl;

        cin >> userMenuSelect;

        switch(userMenuSelect){
            case 1: 
                cout << "Enter word to search for: " << endl;
                cin >> firstArgString;
                (mainBST->search(firstArgString)) ? cout << "true" : cout << "false";
                cout << endl;
                mainBST->printTree();
                break;
            case 2:
                (mainBST->getRoot() == NULL) ? cout << "NULL" : cout << "not NULL";
                cout << endl;
                cout << "Enter word to insert: " << endl;
                cin >> firstArgString;
                (mainBST->getRoot() == NULL) ? cout << "NULL" : cout << "not NULL";
                cout << endl;
                mainBST->insert(firstArgString);
                cout << "*inserted*" << endl;
                mainBST->printTree();
                break;
            case 3:
                cout << "Enter word to delete: " << endl;
                cin >> firstArgString;
                mainBST->remove(firstArgString);
                cout << "*removed*" << endl;
                mainBST->printTree();
                break;
            case 4:
                cout << "Starting sort operation...";
                mainBST->sort();
                cout << "sorted." << endl;
                break;
            case 5:
                cout << "Enter two words for ranged search." << endl;
                cout << "First word (lower bound): " << endl;
                cin >> firstArgString;
                cout << "Second word (upper bound): " << endl;
                cin >> secondArgString;
                mainBST->rangeSearch(firstArgString, secondArgString);
                mainBST->printTree();
                break;
            default:
                break;
        }
    }
    return 0;
}
