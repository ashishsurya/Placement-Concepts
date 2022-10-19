/*
Memoization.
*/

class Solution {
public:
    int minFallingPathSum(int r,int c,int n,vector<vector<int>> matrix,vector<vector<int>> & dp) {
        // BASE CASE
        if(c < 0 || c >= n) return 1e9;
        if(r == n-1) return matrix[n-1][c];
        
        // RETURN IF ALREADY COMPUTED
        if(dp[r][c] != -1) return dp[r][c];
        
        // DO ALL THE STUFF
        int ldg = matrix[r][c] + minFallingPathSum(r+1,c-1,n,matrix,dp);
        int d = matrix[r][c] + minFallingPathSum(r+1,c,n,matrix,dp);
        int rdg = matrix[r][c] + minFallingPathSum(r+1,c+1,n,matrix,dp);
        
        // STORE THE VALUE AND RETURN
        return dp[r][c] = min(ldg , min(d,rdg));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        // MULTIPLE STARTING POINTS.
        for(int j=0;j<n;j++) {
            ans = min(ans,minFallingPathSum(0,j,n,matrix,dp));
        }
        return ans;
    }
};

/*
TABUALTION
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==1) return matrix[0][0];
        int ans = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        // FILLLING  THE LAST ROW OF DP TABLE 
        for(int j=0;j<n;j++) dp[n-1][j] = matrix[n-1][j];
        
        // FILLING REMAINING TABLE.
        for(int i=n-2;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                int ldg,d,rdg; // INITIALIZING VARIABLES.
                ldg = matrix[i][j];
                
                
                // EEDGE CASE HANDLING
                (j==0) ? ldg+= 1e9 : ldg+=dp[i+1][j-1];
                d = matrix[i][j] + dp[i+1][j];
                rdg = matrix[i][j];
                // EEDGE CASE HANDLING                
                (j==n-1) ? rdg += 1e9 : rdg += dp[i+1][j+1];
                dp[i][j] = min(ldg , min(d,rdg));
                
                // UPDATING THE FINAL ANS.
                if(i==0) {
                    ans = min(ans , dp[0][j]);
                }
            }
        }
        return ans;
    }
};
