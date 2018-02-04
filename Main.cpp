#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){

string input = "";
int number;


while(input != "exit"){
    cout << "input node word or 'exit' to quit: " << endl;
    cin >> input;
    cout << "input count: " << endl;
    cin >> number;

    cout << "input: " << input << endl;
    cout << "count: " << number << endl;

}











    return 0;
}