# Count Subsets with Sum K 

- ### Brute Force

  Time Complexity - O(2^N)
  
  ```cpp
  #include <bits/stdc++.h> 
  int f(int idx,vector<int> & num, int k) {
      if(k==0) return 1;
      if(idx == 0) return num[0] == k;
      int N = f(idx-1,num,k);
      int Y = 0;
      if(num[idx] <= k) {
          Y = f(idx-1,num , k-num[idx]);
      }
      return N + Y;
  }
  int findWays(vector<int> &num, int tar) {
      // Write your code here.
      return f(num.size()-1,num,tar);
  }
  ```
  
- ### Memoization
  
  Time Complexity - O(N*N)
  
  ```cpp
  #include <bits/stdc++.h> 
  int f(int idx,vector<int> & num, int k,vector<vector<int>> & dp) {
      if(k==0) return 1;
      if(idx == 0) return num[0] == k;
      if(dp[idx][k] != -1) return dp[idx][k];
      int N = f(idx-1,num,k,dp);
      int Y = 0;
      if(num[idx] <= k) {
          Y = f(idx-1,num , k-num[idx],dp);
      }
      return dp[idx][k] = N + Y;
  }
  int findWays(vector<int> &num, int k) {
      // Write your code here.
      int n = num.size();
      vector<vector<int>> dp(n,vector<int>(k+1, -1));
      return f(n-1,num,k,dp);
  }
  

- Tabulation
  ```cpp
  #include <bits/stdc++.h> 
  int findWays(vector<int> &num, int k)
  {
      // Write your code here.
      int n = num.size();
      vector<vector<int>> dp(n,vector<int>(k+1, 0));
      for(int i=0;i<n;i++){
          dp[i][0] = 1;
      }
      if(num[0] <= k) {
          dp[0][num[0]] = 1;
      }
      for(int i=1;i<n;i++) {
          for(int j=1;j<k+1;j++){
              int N = dp[i-1][j];
              int Y = 0;
              if(num[i] <= j) {
                  Y = dp[i-1][j - num[i]];
              }
              dp[i][j] = N + Y;
          }
      }
         return dp[n-1][k];
  }
  ```
