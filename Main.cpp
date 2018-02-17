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
#include <algorithm>


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
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            find_and_replace(temp, ",", "");
            find_and_replace(temp, ".", "");
            find_and_replace(temp, "!", "");
            find_and_replace(temp, "?", "");
            find_and_replace(temp, "(", "");
            find_and_replace(temp, ")", "");
            find_and_replace(temp, "*", "");
            find_and_replace(temp, "&", "");
            find_and_replace(temp, ":", "");
            find_and_replace(temp, ";", "");
            if(temp != ""){
                mainBST->insert(temp);
                wordCount++;
            }
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
            find_and_replace(temp, ",", "");
            find_and_replace(temp, ".", "");
            find_and_replace(temp, "!", "");
            find_and_replace(temp, "?", "");
            find_and_replace(temp, "(", "");
            find_and_replace(temp, ")", "");
            find_and_replace(temp, "*", "");
            find_and_replace(temp, "&", "");
            find_and_replace(temp, ":", "");
            find_and_replace(temp, ";", "");
            if (temp != ""){
                table->insertWord(temp);
            }
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

                bool hbool, bbool;
                cout << "Enter word to search for: " << endl;
                cin >> firstArgString;
                
                auto start0 = chrono::high_resolution_clock::now();
                bbool = (mainBST->search(firstArgString)) ? true : false;
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;
                
 
                auto start1 = chrono::high_resolution_clock::now();  
                hbool = (table->searchWord(firstArgString) != -1)? true : false;
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;
                (bbool || hbool) ? cout<< "true" : cout << "false";


                cout << endl;
                cout << "BST: " << elapsed0.count() << " s\n";
                cout << "HashTable: " << elapsed1.count() << " s\n";  


                break;
            }
            case 2:
            {
                cout << "Enter word to insert: " << endl;
                cin >> firstArgString;

                auto start0 = chrono::high_resolution_clock::now();
                mainBST->insert(firstArgString);
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;

                auto start1 = chrono::high_resolution_clock::now();
                table->insertWord(firstArgString);
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;

                cout << "BST: " << elapsed0.count() << endl;
                cout << "Hash: " << elapsed1.count() << endl;

                break;
            }
            case 3:
            {
                cout << "Enter word to delete: " << endl;
                cin >> firstArgString;
                
                auto start0 = chrono::high_resolution_clock::now();
                mainBST->remove(firstArgString);
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;

                auto start1 = chrono::high_resolution_clock::now();
                table->deleteWord(firstArgString);
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;

                cout << "BST: " << elapsed0.count() << endl;
                cout << "Hash: " << elapsed1.count() << endl;

                break;
            }
            case 4:
             {
                outputToFile("reported", "output.txt");
                system("rm output.txt");

                auto start0 = chrono::high_resolution_clock::now();
                mainBST->sort();
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;

                outputToFile("\n", "output.txt");

                auto start1 = chrono::high_resolution_clock::now();
                table->sortWords();
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;

                cout << "BST: " << elapsed0.count() << endl;
                cout << "Hash: " << elapsed1.count() << endl;

                break;
             }
            case 5:
            {
                cout << "Enter two words for ranged search." << endl;
                cout << "First word (lower bound): " << endl;
                cin >> firstArgString;
                cout << "Second word (upper bound): " << endl;
                cin >> secondArgString;
                
                auto start0 = chrono::high_resolution_clock::now();
                mainBST->rangeSearch(firstArgString, secondArgString);
                auto finish0 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed0 = finish0 - start0;

                cout << endl << endl;

                auto start1 = chrono::high_resolution_clock::now();
                table->rangeSearch(firstArgString, secondArgString);
                auto finish1 = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed1 = finish1 - start1;

                cout << "BST: " << elapsed0.count() << endl;
                cout << "Hash: " << elapsed1.count() << endl;

                
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

