#include <bits/stdc++.h>
using namespace std;

void f(int idx, vector<int> &array, vector<int> v, int k)
{
  if (idx >= v.size())
  {
    if (array.size() == k)
    {

      for (auto it : array)
      {
        cout << it << " ";
      }
      cout << endl;
    }
      return;
  }
  array.push_back(v[idx]);
  f(idx + 1, array, v, k);
  array.pop_back();
  f(idx + 1, array, v, k);
}

int main()
{
  vector<int> v = {1, 3, 2, 4, 3, 4, 5, 3, 4, 3};
  vector<int> array;
  f(0, array, v, 6);
  return 0;
}
