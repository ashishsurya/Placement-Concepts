#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
  vector<int> ans;
  int n = s.size();
  int m = p.size();
  if(m > n)
    return ans;

  unordered_map<char, int> pmap;
  unordered_map<char, int> smap;
  for (int i = 0; i < m;i++) {
    pmap[p[i]]++;
    smap[s[i]]++;
  }



  int i = 0;
  int j = m - 1;
  cout << "STATED" << endl;
  while (i <= n - m)
  {
    if(pmap == smap) {
      ans.push_back(i);

    } else {
      smap.erase(s[i]);
      smap[s[j+1]]++;
    }
    i++;
    j++;
  }

  return ans;
}

int main()
{
  string s, p;
  cin >> s >> p;
  vector<int> x = findAnagrams(s, p);

  for(int i:x) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
