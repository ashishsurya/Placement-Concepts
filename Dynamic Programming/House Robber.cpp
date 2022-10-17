#include<bits/stdc++.h>
using namespace std;

int FindMaxSum(int idx, int arr[],int n,vector<int> &dp) {
  if(idx >= n) {
    return 0;
  }

  if(dp[idx] != -1) {
    return dp[idx];
  }

  int choose = arr[idx] + FindMaxSum(idx + 2, arr, n,dp);
  int notChoose = 0 + FindMaxSum(idx + 1, arr, n,dp);
  return dp[idx] = max(choose, notChoose);
}

int FindMaxSum(int arr[] , int n) {
  vector<int> dp(n, -1);
  return FindMaxSum(0, arr, n,dp);
}


int TabulatedFindMaxSum(int arr[], int n) {
  vector<int> dp(n, 0);
  dp[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    int choose = arr[i];
    if(i < n-2)
      choose += dp[i + 2];
    int notChoose = 0 + dp[i + 1];
    dp[i] = max(notChoose, choose);
  }
  return dp[0];
}

int SpaceOptimizedFindMaxSum(int arr[], int n){
  int next = 0;
  int nextsNext = 0;

  for (int i = n - 1; i >= 0;i--) {
    next = arr[i];
    if(i < n-2)
      nextsNext = next;
  }
}

int main() {
  int arr[] = {5, 5, 10, 100, 10, 5};
  cout << TabulatedFindMaxSum(arr, 6) << endl;
  return 0;
}
