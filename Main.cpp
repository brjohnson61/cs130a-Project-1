#include <stdio.h>
#include <string>
#include <iostream>
#include "Node.hpp"
#include "HashTable.hpp"
#include "BST.hpp"
#include <iomanip>
#include <fstream>
#include <experimental/filesystem>
#include <vector>
#include <cstring>


namespace fs = std::experimental::filesystem;
using namespace std;


//All credit for find_and_replace function goes to: http://bits.mdminhazulhaque.io/cpp/find-and-replace-all-occurrences-in-cpp-string.html
void find_and_replace(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}

void readFilesToVec(vector<string>& fileNames, string path){
     for(auto& p: fs::recursive_directory_iterator(path)){
        string newPath = p.path().string();
        if(!is_directory(p.path())){
            int index = newPath.find("._");
            if( index < 0){
                find_and_replace(newPath, "/", "//");
                fileNames.push_back(newPath);
            }
        }
    }
}



int main(){

    BST* mainBST = new BST();
    HashTable* table = new HashTable(100);
    vector<string> fileList;

    readFilesToVec(fileList, "hotels-small");

    unsigned int count = 0;
    string word;

    for(int i=0; i< fileList.size(); i++){
        ifstream inFile(fileList[i].c_str());
        string temp = "";
        while(inFile >> temp){
            mainBST->insert(temp);
        }
        inFile.close();
    }

    // // ifstream inFile("hotels-small//beijing//china_beijing_autumn_garden_courtyard_hotel");
    // // cout <<  << endl;
    // // while(inFile >> word){
    // //     cout << word << endl;
    // // }
    // // inFile.close();

    // // for(int i = 0; i < fileList.size(); i++){
    // //     ifstream inFile;
    // //     char *cFile = new char[fileList[i].length()+1];
    // //     strcpy(cFile, fileList[i].c_str());
    // //     inFile.open(cFile);
    // //     cout << fileList[i] << endl;
    // //     while(inFile >> word){
    // //         cout << word << endl;
    // //     }
    // //     inFile.close();
    // // }

    // vector<string> testvec;

    // string tempString = "";

    // for(int i = 0; i< fileList.size(); i++){
    //     for(int j=0; j< fileList[i].length(); j++){
    //         tempString += fileList[i].at(j);
    //     }
    //     testvec.push_back(tempString);
    //     tempString = "";
    // }

    // //testvec.push_back(tempString);

    // cout << fileList[2] << endl;
    // string myString = testvec[0];

    // ifstream inFile;
    // inFile.open(myString.c_str());
    // string car;
    // while(inFile >> car){
    //     cout << car << endl;
    //     mainBST->insert(car);
    // }
    // inFile.close();

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