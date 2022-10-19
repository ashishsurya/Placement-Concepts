/*
MEMOIZED
T.C => O(N*N)
S.C => O(N*N + N)
*/

class Solution {
public:
    int minimumTotal(int r,int c,int n,vector<vector<int>> triangle,vector<vector<int>> & dp) {
      // base case
      if(r == n-1)
        return triangle[n - 1][c];
      // return if already computed
      if(dp[r][c] != -1)
        return dp[r][c];
      // explore all cases

      int d = triangle[r][c] + minimumTotal(r + 1, c, n, triangle,dp);
      int dg = triangle[r][c] + minimumTotal(r + 1, c+1, n, triangle,dp);

      return dp[r][c] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<vector<int>> dp(n);
      for (int i = 0; i < n;i++) {
        dp[i] = vector<int>(i+1, -1);
      }
      return minimumTotal(0, 0, n, triangle,dp);
    }
};

/*
TABULATION
T.C => O(N*N)
S.C => O(N*N)
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<vector<int>> dp(n);
      for (int i = 0; i < n;i++) {
        dp[i] = vector<int>(i+1, 0);
      }
        
      // start tabulation
      for(int j=0;j<n;j++) {
          dp[n-1][j] = triangle[n-1][j];
      }
        
      for(int i=n-2;i>=0;i--) {
          for(int j=i;j>=0;j--) {
              int d = triangle[i][j] + dp[i+1][j];
              int dg = triangle[i][j] + dp[i+1][j+1];
              
              dp[i][j] = min(d,dg);
          }
      }
        
    return dp[0][0];
        
    }
};
