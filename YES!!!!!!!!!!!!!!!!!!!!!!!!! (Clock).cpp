// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

string operator*(const string& s, int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

void printWordFrequency(string input)
{
    map<string, int> Map;
 
    // String for storing the words
    string latestWord;
 
    for (int i = 0; i < input.size(); i++) {
 
        if (input[i] == ' ') {
 
            if (Map.find(latestWord) == Map.end()) {
                Map.insert(make_pair(latestWord, 1));
                latestWord = "";
            }
 
            else {
                Map[latestWord]++;
                latestWord = "";
            }
        }
 
        else
            latestWord += input[i];
    }
 
    if (Map.find(latestWord) == Map.end())
        Map.insert(make_pair(latestWord, 1));
 
    else
        Map[latestWord]++;
  
    for (auto& it : Map) {
        cout << it.first << " - "
             << it.second
             << endl;
    }
}

void printWordGraph(string input)
{
    map<string, int> Map;
 
    // String for storing the words
    string latestWord;
 
    for (int i = 0; i < input.size(); i++) {
 
        if (input[i] == ' ') {
 
            if (Map.find(latestWord) == Map.end()) {
                Map.insert(make_pair(latestWord, 1));
                latestWord = "";
            }
 
            else {
                Map[latestWord]++;
                latestWord = "";
            }
        }
 
        else
            latestWord += input[i];
    }
 
    if (Map.find(latestWord) == Map.end())
        Map.insert(make_pair(latestWord, 1));
 
    else{
        Map[latestWord]++;
    }
        
    //int repNum = it.second;
    //string asterisk = "*";
    
    string asterisk = "*";
    
    for (auto& it : Map) {
    int repNum = it.second;
        //for (int x = 1; x == repNum; x++) {
            //asterisk = "*" + asterisk;
        //}
    cout << it.first 
         << " "
         << asterisk * it.second //asterisk
         << endl;
    string asterisk = "*";
    }
}


int displayMenu() {
    
    int input;
    cout << "*******************************" << endl;
    cout << "******** Corner Grocer ********" << endl;
    cout << "* 1- Input Word               *" << endl;
    cout << "* 2- Print List and Freqency  *" << endl;
    cout << "* 3- Print Graph              *" << endl;
    cout << "* 4- Exit The Program         *" << endl;
    cout << "*******************************" << endl;
    cout << "Enter Number: " << endl;
    cin >> input;
    cin.ignore();
    return input;
    
}

int main() {
    
    int input;
    int runStatus = 1;
    int fileLine;
    string newInput;
    string line;
    string totalText;
    ifstream myfile ("example.txt");
    
    if (myfile.is_open()) {
    while (fileLine != 104) {
        getline(myfile, line);
        totalText = line + " " + totalText;
        fileLine++;
    }
        myfile.close();
    }
    
    else {
        cout << "Error 104: Unable to open file" << endl; 
        cout << "Error Code: -1795716720" << endl; 
        runStatus = 0;
    }
    
    while (runStatus == 1) {
        input = displayMenu();
        
        if (input == 1) {
            cout << "Enter New Input:" << endl;
            cin >> newInput;
            totalText = newInput + " " + totalText;
        }
        else if (input == 2) {
            printWordFrequency(totalText);
        }
        else if (input == 3) {
            printWordGraph(totalText);
            //cout << "Feature in development" << endl;;
        }
        else if (input == 4) {
            runStatus = 0;
        }
        else {
           cout << "Invalid Input" << endl; 
        }
    }
    return 0;
}