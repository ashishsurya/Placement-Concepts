#include <bits/stdc++.h>
using namespace std;

/*
Basic Recursion => T.C - O(2^(m+n))   S.C - O(m+n)
								   recursion stack space
Memoization => T.C - O(n*m)   S.C - O((n-1) + (m-1)) +      O(n*m)
													  recursion stack space

Tabulation =>  T.C - O(n*m)   S.C - O(n*m)

Space Optimized => T.C - O(n*m) S.C -  
*/

int uniquePaths(int r, int c, int m, int n, vector<vector<int>> &dp)
{
	// basecase
	if (r == 0 && c == 0)
		return 1;
	if (r < 0 || c < 0)
		return 0;

	if (dp[r][c] != -1)
		return dp[r][c];

	// all possible stuffs
	int up = uniquePaths(r - 1, c, m, n, dp);
	int left = uniquePaths(r, c - 1, m, n, dp);

	return dp[r][c] = up + left;
}

int uniquePaths(int n, int m)
{
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 && j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				int up = 0, left = 0;
				if (i > 0)
					up = dp[i - 1][j];
				if (j > 0)
					left = dp[i][j - 1];
				dp[i][j] = up + left;
			}
		}
	}
	return dp[n - 1][m - 1];
}

// space otpimized;
int uniquePaths(int m, int n) {
        vector<int> prev(m,0);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m,0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = temp[j - 1];
                    temp[j] = up + left;
                }
            prev = temp;
        }
        return prev[m-1];
    }
