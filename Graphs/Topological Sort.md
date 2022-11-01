# Topological Sort
## Intutuion
  We need store the node after the completion of it's dfs traversal.
  
```cpp
class Solution
{
    private:
    void dfs(int node , vector<int> & visited , stack<int> & st , vector<int> adj[]) {
        visited[node] = 1;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,st,adj);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++) {
	        if(!visited[i]) {
	            dfs(i,visited,st,adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

```
