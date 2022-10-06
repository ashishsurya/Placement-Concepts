int findMaxSum(int idx, int * arr , int n,vector<int> & dp) {
        if(idx == 0) return arr[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int pick = arr[idx] + findMaxSum(idx-2,arr,n,dp);
        int notpick = 0 + findMaxSum(idx - 1,arr,n,dp);
        return dp[idx] = max(pick,notpick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return findMaxSum(n-1,arr , n,dp);
	}