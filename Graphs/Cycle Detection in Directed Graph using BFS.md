# Cycle Detection in Directed Graph using BFS
Basically while using DFS to find cycle directed graph we used two visited arrays one for global nodes and one for traversal , we have reset the values of traversal visited array while backtracking.<br /><br />
But in BFS we doesn't have any backtracking.<br />
We will be using <b> <a href="https://github.com/ashishsurya/Placement-Concepts/blob/master/Graphs/Kahns's%20Algorithm.md">Kahn's Algorithm</a></b>

```cpp
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // calculating indegree.
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		//vector<int> topo;
		int cnt = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			//topo.push_back(node);
			cnt++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

	    if(cnt == V) return false;
	    return true;
    }
};
```
