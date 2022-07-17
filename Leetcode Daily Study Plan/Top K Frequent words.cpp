#include <bits/stdc++.h>
using namespace std;

vector<string> topKFrequent(vector<string> &words, int k)
{


  auto compare = [](pair<string, int> a, pair<string, int> b)
  {
    if (a.second == b.second)
      return a.first.length() <b.first.length();
    return a.second > b.second;
  };

  priority_queue<pair<string, int>,
                 vector<pair<string, int>>, decltype(compare)>
      heap(compare);

  map<string, int> freq;
  for (string s : words)
  {
    freq[s]++;
  }

  for (auto &r : freq)
  {
    if (heap.size() < k)
    {
      heap.push({r.first, r.second});
    }
    else
    {
      if (heap.top().second < r.second)
      {
        heap.pop();
        heap.push({r.first, r.second});
      }
    }
  }

  if(k==1) {
    return {heap.top().first};
  }

  vector<string> ans(k);
  int index = k-1;


  while (!heap.empty())
  {
    ans[index--] = heap.top().first;
    heap.pop();
  }
  
  return ans;
}

int main()
{

  // int n, k;
  // cin >> n >> k;
  // vector<string> words(n);
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> words[i];
  // }

  // vector<string> topK = topKFrequent(words, k);

  // for (string s : topK)
  // {
  //   cout << s << endl;
  // }

  string a, b;
  cin >> a >> b;
  cout << a.compare(b) << endl;

  return 0;
}
