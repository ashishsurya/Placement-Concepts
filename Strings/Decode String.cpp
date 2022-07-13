// https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
  string ans = "";
  stack<char> stack;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != ']')
    {
      stack.push(s[i]);
    }
    else
    {
      string substr = "";
      // EXTRACT THE STRING BETWEEN []
      while (stack.top() != '[')
      {
        substr += stack.top();
        stack.pop();
      }

      string k = ""; // to store the number to multiply the substr.
      while (!stack.empty() && stack.top() >= '1' && stack.top() <= '9')
      {
        k += stack.top();
        cout << k << endl;
        stack.pop();
      }
      
      for (int i = 0; i < stoi(k); i++)
      {
        ans += substr;
      }
    }
  }

  return ans;
}

int main()
{

  string s;
  cin >> s;

  cout << decodeString(s) << endl;

  return 0;
}
