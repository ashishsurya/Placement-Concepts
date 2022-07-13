#include <bits/stdc++.h>
using namespace std;

bool ispossible(int n, vector<int> seats, int m)
{
  if (n > m)
    return false;

  for (int i = 0; i < m && n>0; i++)
  {
    if (seats[i] == 0)
    {
      if (i == 0)
      {
        if (seats[i + 1] == 0)
        {
          seats[i] = 1;
          n--;
        }
      }
      else if (i == m - 1)
      {
        if (seats[i - 1] == 0)
        {
          seats[i] = 1;

          n--;
        }
      }
      else
      {
        if (seats[i - 1] == 0 && seats[i + 1] == 0)
        {
          seats[i] = 1;

          n--;
        }
      }
    }
  }

  return n == 0;
}

int main()
{

  int n, m;
  cin >> n >> m;
  vector<int> seats(m);
  for (int i = 0; i < m; i++)
  {
    cin >> seats[i];
  }

  cout << ispossible(n, seats, m) << endl;

  return 0;
}
