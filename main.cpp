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

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1;
}

string reformatBinaryString(const string &s) {
   if (!s.size()) { return ""; }
   
   std::stringstream ss;
   ss << s[0];
   
   for (int i = 1; i < s.size(); i++) {
       if ((i % 4) == 0) {
        ss << ' ' << s[i];
       } else {
           ss << s[i];
       }
   }
   
   return ss.str();
}

string removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string ADDER(string first, string second) {
    
    string result;
    int length = makeEqualLength(first, second);
    int carry = 0;
    
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
        
        cout << "The carry in is " 
         << carry
         << ".     ";
        
        int sum = (firstBit ^ secondBit ^ carry)+'0';
        
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
    
    if (carry) {
        result = '1' + result;
    }
 
    return result;
}

int main() {
    string p, q;
    
    cout << "\nBinary Term #1 "
         << endl;
    getline(cin, p);
    p = removeSpaces(p);
    
    cout << "\nBinary Term #2 "
         << endl;
    getline(cin, q);
    q = removeSpaces(q);
    
    cout << "\nThe answer is "
         << reformatBinaryString(ADDER(p, q))
         << "."
         << endl;
}