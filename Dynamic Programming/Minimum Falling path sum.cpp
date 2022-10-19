/*
Memoization.
*/

class Solution {
public:
    int minFallingPathSum(int r,int c,int n,vector<vector<int>> matrix,vector<vector<int>> & dp) {
        if(c < 0 || c >= n) return 1e9;
        if(r == n-1) return matrix[n-1][c];
        if(dp[r][c] != -1) return dp[r][c];
        int ldg = matrix[r][c] + minFallingPathSum(r+1,c-1,n,matrix,dp);
        int d = matrix[r][c] + minFallingPathSum(r+1,c,n,matrix,dp);
        int rdg = matrix[r][c] + minFallingPathSum(r+1,c+1,n,matrix,dp);
        return dp[r][c] = min(ldg , min(d,rdg));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++) {
            ans = min(ans,minFallingPathSum(0,j,n,matrix,dp));
        }
        return ans;
    }
};
