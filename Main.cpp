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
#include <chrono>


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
    
    vector<string> fileList;

    readFilesToVec(fileList, "hotels-small");

    unsigned int count = 0;
    string word;
    int wordCount = 0;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i< 2; i++){
        ifstream inFile(fileList[i].c_str());
        string temp = "";
        while(inFile >> temp){
            mainBST->insert(temp);
            wordCount++;
        }
        inFile.close();
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed Time: " << elapsed.count() << " s\n";

    HashTable* table = new HashTable(wordCount);
    for (int i = 0; i<2;i++){
        ifstream inFile(fileList[i].c_str());
        string temp = "";
        while(inFile >> temp){
            table->insertWord(temp);
        }
        inFile.close();
    }


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
            {
                cout << "Enter word to search for: " << endl;
                cin >> firstArgString;
                
                auto start0 = chrono::high_resolution_clock::now();
                (mainBST->search(firstArgString)) ? cout << "true" : cout << "false";
                auto finish0 = chrono::high_resolution_clock::now();
                cout << endl;
                chrono::duration<double> elapsed0 = finish0 - start0;
                cout << "BST: " << elapsed0.count() << " s\n";
 
                auto start1 = chrono::high_resolution_clock::now();  
                (table->searchWord(firstArgString) != -1)? cout << "true": cout << "false";
                auto finish1 = chrono::high_resolution_clock::now();
                cout << endl;
                chrono::duration<double> elapsed1 = finish1 - start1;
                cout << "HashTable: " << elapsed1.count() << " s\n";  


                break;
            }
            case 2:
            {
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
            }
            case 3:
            {
                cout << "Enter word to delete: " << endl;
                cin >> firstArgString;
                mainBST->remove(firstArgString);
                table->deleteWord(firstArgString);
                cout << "*removed*" << endl;
                mainBST->printTree();
                break;
            }
            case 4:
             {
                cout << "Starting sort operation...";
                mainBST->printTree();
                mainBST->sort();
                table->sortWords();
                cout << "sorted." << endl;
                break;
             }
            case 5:
            {
                cout << "Enter two words for ranged search." << endl;
                cout << "First word (lower bound): " << endl;
                cin >> firstArgString;
                cout << "Second word (upper bound): " << endl;
                cin >> secondArgString;
                mainBST->rangeSearch(firstArgString, secondArgString);
                table->rangeSearch(firstArgString, secondArgString);
                mainBST->printTree();
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}

