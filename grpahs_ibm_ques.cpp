#include<bits/stdc++.h>
using namespace std;

bool allVisited(vector<bool> & visited) {
  bool allVisited = true;
  for (int i = 1; i <= visited.size()-1; i++)
  {
    if(!visited[i]) {
      allVisited = false;
      break;
    }
  }

  return allVisited;
}

/// @brief 
/// @param sv 
/// @param graph 
/// @param visited 
/// @param A 
void dfs(int sv,vector<vector<int>> graph,vector<bool> & visited,vector<int> & A) {
  visited[sv] = true;
  A.push_back(sv);

  if(allVisited(visited))
    return;
  
  // our current node is sv
  // current node's neighbours are graph[sv].

  for(auto neighbour : graph[sv]) {
    if(!visited[neighbour]) {
      dfs(neighbour, graph, visited, A);
    }
  }
  if(allVisited(visited))
    return;
  dfs(graph[sv][0], graph, visited, A);
}

/// @brief 
/// @return 
int main() {

  int vertices,edges;
  cin >> vertices >> edges;

  vector<vector<int>> graph(vertices + 1);
  vector<bool> visited(vertices + 1, false);

  for (int i = 0; i < edges;i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  

  // sort the neighbours in descenin order.
  for(auto &x:graph) {
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());

  }

  for(auto node:graph) {
    for(auto neighbour : node) {
      cout << neighbour << " ";
    }
    cout << endl;
  }

  vector<int> A;

  dfs(vertices, graph, visited, A);

for(auto it:A) {
  cout << it << endl;
}
  return 0;
}


/*

5 5
1 4
1 5
2 3
3 4
4 5

*/
