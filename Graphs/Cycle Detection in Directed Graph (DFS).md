# Cycle Detection in Directed Graph (DFS)	
https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-using-dfs/ <br/>
We cannot apply the same logic as Undirected graph.<br/>

We should maintain another visited array for the current dfs traversal.

```cpp
#include <vector>
using namespace std;

bool cycleCheck(int sv, vector<int> & vis , vector<int> & dfsVis,vector<vector<int>> edges) {
  vis[sv] = 1;
  dfsVis[sv] = 1;
  for(auto it : edges[sv]) {
    if(!vis[it]) {
      if(cycleCheck(it , vis,dfsVis,edges)) return true;
    } else if(dfsVis[it]) {
      return true;
    }
  }
  dfsVis[sv] = 0;
  return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  // Write your code here.
  int n = edges.size();
  int n = V;
  
  vector<int> vis(n, 0);
  vector<int> dfsVis(n,0);
  for(int i=0;i<n;i++) {
    if(!vis[i]) {
      if(cycleCheck(i,vis,dfsVis,edges)) return true;
    }
  }
  return false;
}
```
