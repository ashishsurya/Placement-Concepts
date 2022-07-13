#include <bits/stdc++.h>
using namespace std;

vector<int> getInterestingHotels(vector<int> &hotels, int k)
{
  vector<int> ans;

  int n = hotels.size();
  // CHECKING UNTIL n-k ELEMENTS
  for (int i = 0; i < n - k; i++)
  {
    int curr = hotels[i];
    bool isInteresting = true;
    for (int j = 0; j < k; j++)
    {
      if (hotels[j] >= curr)
        isInteresting = false;
      break;
    }
    if (isInteresting)
    {
      ans.push_back(i);
    }
  }

  for (int i = n - k; i < n - 1; i++)
  {
    int curr = hotels[i];
    int isInteresting = true;
    for (int j = i + 1; j < n; j++)
    {
      if (hotels[j] >= curr)
      {
        isInteresting = false;
        break;
      }
      if(isInteresting){
        ans.push_back(i);
      }
    }
  }

  ans.push_back(n - 1);
  return ans;
}

int main()
{

  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> hotels(n);
    for (int i = 0; i < n;i++) {
      int x;
      cin >> x;
      hotels.push_back(x);
    }
    vector<int> interestingHotels = getInterestingHotels(hotels, k);
    for(int i:interestingHotels) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
