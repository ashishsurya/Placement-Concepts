# Number of Distinct Islands [dfs multisource]
https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1 <br>
This is a simple expansion of number of islands problem.<br>
We need to translate every island to origin(0,0) before adding it to the list of islands.<br>
To get distinct islands we will be storing all islands using set data structure.<br>

```cpp
class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> & visited , vector<vector<int>>& grid,vector<pair<int,int>> & island,int row0,int col0) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        island.push_back({row - row0 , col - col0});
        int R[] = {-1,0,1,0};
        int C[] = {0,1,0,-1};
        for(int i=0;i<4;i++) {
            int nR = row + R[i];
            int nC = col + C[i];
            if(nR >= 0 && nC >= 0 && nR < n && nC < m && visited[nR][nC] == 0 && grid[nR][nC] == 1) {
                dfs(nR,nC,visited,grid,island,row0,col0);
            }
        }
    }  
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        set<vector<pair<int,int>>> disislands;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++ ){
                if(visited[i][j] == 0 && grid[i][j] == 1) {
                    vector<pair<int,int>> island;
                    dfs(i,j,visited,grid,island,i,j);
                    disislands.insert(island);
                }
            }
        }
        return disislands.size();
    }
};
```
