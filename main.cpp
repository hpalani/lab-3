/*
 NAME: Harish Palani
 CRN: 41600
 ASSIGNMENT: Lab 3
 SOURCES: stackoverflow.com
 
 TO-DO:
 Handle non-binary input
 Separate HALFADDER & FULLADDER
 Reformat/rename
 Add comments
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string result;
int sum = 0, carry = 0;

int equalize(string &str1, string &str2);
bool isBinary(string str);
string reformatBinaryString(const string &str);
string removeSpaces(string str);
void HALFADDER(int firstBit, int secondBit);
string FULLADDER(string first, string second);

int main() {
    // Run the addition procedure 4 times
    for (int i = 0; i < 4; i++) {
        cout << "\nROUND "
             << i + 1
             << endl;
        
        string p, q;
        
        // Accept first binary term for addition
        cout << "\nBinary Term #1"
             << endl;
        getline(cin, p);
        p = removeSpaces(p);
        
        while (!isBinary(p)) { // Catch non-binary input
            cout << "\nPlease enter a valid binary term."
                 << endl;
            getline(cin, p);
            p = removeSpaces(p);
        }
        
        // Accept second binary term for addition
        cout << "\nBinary Term #2"
             << endl;
        getline(cin, q);
        q = removeSpaces(q);
        
        while (!isBinary(q)) { // Catch non-binary input
            cout << "\nPlease enter a valid binary term."
                 << endl;
            getline(cin, q);
            q = removeSpaces(q);
        }
        
        // Output addition result
        cout << "\nThe answer is "
             << reformatBinaryString(FULLADDER(p, q))
             << "."
             << endl;
        
        sum = 0;
        carry = 0;
        result.clear();
    }
}

void HALFADDER(int firstBit, int secondBit) {
    cout << "The carry in is " 
         << carry
         << ".     ";
    
    sum = (firstBit ^ secondBit ^ carry)+'0';
    
    cout << "The sum is " 
         << sum-'0'
         << ".     ";
     
    result = (char)sum + result;
    carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    
    cout << "The carry out is " 
         << carry
         << ".     "
         << endl;
}

string FULLADDER(string first, string second) {
    int length = equalize(first, second);
    
    cout << "\nThe numbers to be added are " 
         << reformatBinaryString(first)
         << " and "
         << reformatBinaryString(second)
         << ".\n"
         << endl;
    
    
    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        
        cout << "The bits are " 
             << firstBit
             << " and "
             << secondBit
             << ".     ";
        
        HALFADDER(firstBit, secondBit);
    }
    
    if (carry) {
        result = '1' + result;
    }
 
    return result;
}

// Devise binary strings of equal lengths
int equalize(string &str1, string &str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    
    if (len1 < len2) {
        for (int i = 0 ; i < len2 - len1 ; i++) {
            str1 = '0' + str1;
        }
        return len2;
    } else if (len1 > len2) {
        for (int i = 0 ; i < len1 - len2 ; i++) {
            str2 = '0' + str2;
        }
    }
    
    return len1;
}

// Check if input string is binary
bool isBinary(string str) {
    bool isBinary = true;
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) != '0' && str.at(i) != '1') {
            isBinary = false;
        }
   }
   return isBinary;
}

// Remove spaces from a string
string removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// Add spaces every 4 bits
string reformatBinaryString(const string &str) {
   if (!str.size()) {
       return "";
   }
   
   std::stringstream ss;
   ss << str[0];
   
   for (int i = 1; i < str.size(); i++) {
       if ((i % 4) == 0) {
        ss << ' ' << str[i];
       } else {
           ss << str[i];
       }
   }
   
   return ss.str();
}