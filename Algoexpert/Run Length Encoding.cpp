#include<bits/stdc++.h>
using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.

  unordered_map<char , int> freq;

  freq[str[0]] = 1;

  char currentChar = str[0]; // keeping track of current elements

  string result = "";

  for(int i=1;i<str.size();i++) {
    if(str[i] != currentChar) {
      result += to_string(freq[currentChar]) + currentChar;
      currentChar = str[i];
    }

    freq[str[i]]++;

    if(freq[str[i]] == 9) {
      result += to_string(9) + str[i];
      freq.erase(str[i]);
    }
    
  }

  result += to_string(freq[currentChar]) + currentChar;

    return result;
}


int main(int argc, char const *argv[])
{
  cout << runLengthEncoding("........______=========AAAA   AAABBBB   BBB") << endl;
  return 0;
}
