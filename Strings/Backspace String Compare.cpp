#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t)
{
  stack<char> ss;
  stack<char> ts;

  for (char c : s)
  {
    if (c == '#')
    {
      if (!ss.empty())
      {
        ss.pop();
      }
      else
      {
        continue;
      }
    }
    else
    {
      ss.push(c);
    }
  }

  for (char c : t)
  {
    if (c == '#')
    {
      if (!ts.empty())
      {
        ts.pop();
      }
      else
      {
        continue;
      }
    }
    else
    {
      ts.push(c);
    }
  }

  if (ss.size() != ts.size())
    return false;

  // in this case both the stacks are of same lenght
  while (!ss.empty())
  {
    if (ss.top() == ts.top())
    {
      ss.pop();
      ts.pop();
    }
    else
    {
      return false;
    }
  }

  return true;
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << backspaceCompare(s, t) << endl;
  return 0;
}
