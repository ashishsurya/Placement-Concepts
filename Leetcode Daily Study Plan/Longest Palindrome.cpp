#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
  unordered_map<char, int> map;

  for (int i = 0; i < s.size();i++) {
    map[s[i]]++;
  }

  int count = 0;
  bool odd_found = false;
  for (auto i : map)
  {
    if(i.second % 2 == 0){
      count += i.second;
    } else {
      odd_found = true;
      count += i.second - 1;
    }
  }

  if(odd_found)
    count++;
  return count;
}

int main()
{

  
  return 0;
}
