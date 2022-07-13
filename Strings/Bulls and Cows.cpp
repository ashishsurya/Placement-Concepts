#include<bits/stdc++.h>
using namespace std;

string getHint(string secret , string guess) {
  int bulls = 0;
  vector<int> numbers(10, 0);

  for (int i = 0; i < secret.size();i++) {
    int s = secret[i] - '0';
    int g = guess[i] - '0';
    if(s == g) {
      bulls++;
    } else {
      numbers[s]++;
      numbers[g]--;
    }
  }

  int x = 0;
  for(int i:numbers){
    if(i > 0)
      x += i;
  }

  int cows = secret.size() - bulls - x;

  return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() {
  string secret, guess;
  cin >> secret >> guess;
  cout << getHint(secret, guess) << endl;
  return 0;
}
