#include <bits/stdc++.h> 


// memoization.
int frogJumpRec(int index , vector<int> & heights,vector<int> & dp) {
    if(index == 0) return 0;
    
    if(dp[index] != -1) return dp[index];
    
    int one = frogJumpRec(index-1,heights,dp) + abs(heights[index] - heights[index-1]);
    int two = INT_MAX;
    if(index > 1) two = frogJumpRec(index-2,heights,dp) + abs(heights[index] - heights[index-2]);
    dp[index] = min(one,two);
    return dp[index];
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);
    dp[0] = 0;
    return frogJumpRec(n-1,heights,dp);
}


// TODO : tabulation.