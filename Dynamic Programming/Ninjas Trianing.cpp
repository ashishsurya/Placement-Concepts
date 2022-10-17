#include<bits/stdc++.h>
using namespace std;
int ninjasTraining(int r, int c, vector<vector<int>> points, int n, vector<vector<int>> &dp)
{
  if (r >= n)
    return 0;
  if (dp[r][c] != -1)
    return dp[r][c];
  int choice1 = points[r][c] + ninjasTraining(r + 1, (c + 1) % 3, points, n, dp);
  int choice2 = points[r][c] + ninjasTraining(r + 1, (c + 2) % 3, points, n, dp);

  return dp[r][c] = max(choice1, choice2);
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // memoization...
    int ans = 0;
    vector<vector<int>> dp(n , vector<int>(3,-1));
    for(int i =0;i<3;i++) {
        ans = max(ans , ninjasTraining(0,i,points,n,dp));
    }
    return ans;


    // tabulation
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // filling bottom row of dp matrix
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
      dp[n - 1][i] = points[n - 1][i];
      ans = max(ans, dp[n - 1][i]);
    }

    for (int i = n - 2; i >= 0;i--) {
      for (int j = 0; j < 3;j++) {
        int choice1 = points[i][j] + dp[i + 1][(j + 1) % 3];
        int choice2 = points[i][j] + dp[i + 1][(j + 2) % 3];
        dp[i][j] = max(choice1, choice2);
        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
}
