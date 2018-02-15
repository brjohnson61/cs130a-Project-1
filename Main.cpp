#include <stdio.h>
#include <string>
#include <iostream>
#include "Node.hpp"
#include "HashTable.hpp"
#include "BST.hpp"
#include <iomanip>
#include <fstream>
#include <experimental/filesystem>

using namespace std;

int main(){
    string tempWord;
    ifstream myfile;
    myfile.open("\\hotels-small\\beijing\\example.txt");
    int count = 0; 

    BST* mainBST = new BST();
    HashTable* table = new HashTable(100);

    if (!myfile.is_open()){
        cout << "Unable to open file" << endl;
        return 0 ; 
    }
    
    
    while (myfile >> tempWord){
        count ++;
        table->insertWord(tempWord);
        mainBST->insert(tempWord);
    }
    

    
    //Hash  Testing
    HashTable myTable = HashTable(10);


    cout << endl << endl;
    cout << "Begin Final Turnin Select Menu" << endl;

    

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
                (table->searchWord(firstArgString) != -1)? cout << "true": cout << "false";
                cout << endl;
                //mainBST->printTree();

                break;
            case 2:
                (mainBST->getRoot() == NULL) ? cout << "NULL" : cout << "not NULL";
                cout << endl;
                cout << "Enter word to insert: " << endl;
                cin >> firstArgString;
                (mainBST->getRoot() == NULL) ? cout << "NULL" : cout << "not NULL";
                cout << endl;
                mainBST->insert(firstArgString);
                table->insertWord(firstArgString);
                cout << "*inserted*" << endl;
                mainBST->printTree();
                break;
            case 3:
                cout << "Enter word to delete: " << endl;
                cin >> firstArgString;
                mainBST->remove(firstArgString);
                table->deleteWord(firstArgString);
                cout << "*removed*" << endl;
                mainBST->printTree();
                break;
            case 4:
                cout << "Starting sort operation...";
                mainBST->sort();
                table->sortWords();
                cout << "sorted." << endl;
                break;
            case 5:
                cout << "Enter two words for ranged search." << endl;
                cout << "First word (lower bound): " << endl;
                cin >> firstArgString;
                cout << "Second word (upper bound): " << endl;
                cin >> secondArgString;
                mainBST->rangeSearch(firstArgString, secondArgString);
                table->rangeSearch(firstArgString, secondArgString);
                mainBST->printTree();
                break;
            default:
                break;
        }
    }
    return 0;
}
