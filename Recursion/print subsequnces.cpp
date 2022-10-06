#include<bits/stdc++.h>
using namespace std;

void f(int idx, vector<int> &array,vector<int> v) {
  if(idx >= v.size()) {
    for(auto it : array) {
      cout << it << " ";
    }
    cout << endl;
    return;
  }
  array.push_back(v[idx]);
  f(idx + 1, array,v);
  array.pop_back();
  f(idx + 1, array,v);
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  vector<int> array;
  f(0, array, v);
  return 0;
}
