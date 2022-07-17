#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
{
  if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 || visited[x][y])
  {
    return false;
  }

  return true;
}

int getArea(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
{
  visited[x][y] = true;
  vector<vector<int>> simulate = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // simulate the process of dfs
  int ans = 1;
  for (auto dir : simulate)
  {
    if (isValid(grid, visited, x + dir[0], y + dir[1]))
    {
      ans += getArea(grid, visited, x + dir[0], y + dir[1]);
    }
  }

  return ans;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
  vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
  int maxArea = 0;
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      if (grid[i][j] == 1 && !visited[i][j])
      {
        maxArea = max(maxArea, getArea(grid, visited, i, j));
      }
    }
  }

  return maxArea;
}

int main()
{

  return 0;
}
