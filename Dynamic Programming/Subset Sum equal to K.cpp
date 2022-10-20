/*
  RECURSION
  O(2^N)
  O(N)
*/
#include <bits/stdc++.h> 
bool f(int idx , int target , vector<int> & arr) {
    if(target == 0) return true;
    if(idx == 0) return target == arr[idx];
    
    bool notPick = f(idx-1,target,arr);
    bool pick = false;
    if(arr[idx] <= target) {
        pick = f(idx-1,target - arr[idx] , arr);
    }
    
    return pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(n-1,k,arr);
}

/*
  MEMOIZATION
  O(N*K)
  O(N + N*K)
*/

bool f(int idx , int target , vector<int> & arr,vector<vector<int>> & dp) {
    if(target == 0) return true;
    if(idx == 0) return target == arr[idx];
    if(dp[idx][target] != -1) return dp[idx][target];
    bool notPick = f(idx-1,target,arr,dp);
    bool pick = false;
    if(arr[idx] <= target) {
        pick = f(idx-1,target - arr[idx] , arr,dp);
    }
    return dp[idx][target] = pick || notPick;
}


/*
  TABULATION
  O(N*K)
  O(N*K)
*/

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    // FILL THE BASE CASES
    for(int j=0;j<k+1;j++) {
        dp[0][j] = j == arr[0];
    }
    
    for(int i=0;i<n;i++) {
        dp[i][0] = true;
    }
    
    for(int idx=1;idx<n;idx++) {
        for(int target=1;target<k+1;target++) {
            bool notPick = dp[idx-1][target];
            bool pick = false;
            if(arr[idx] <= target) {
                pick = dp[idx-1][target-arr[idx]];
            }
            dp[idx][target] = pick || notPick;
        }
    }
    return dp[n-1][k];
}

