#include<vector>
#include<unordered_map>

bool dfs(int node,unordered_map<int, bool>& dfsvisited, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adj){
  visited[node] = true;
  dfsvisited[node] = true;

  for(int neighbor : adj[node]){
    if(!visited[neighbor]){
      if(dfs(neighbor,dfsvisited,visited,adj)){
        return true;
      }
    }
    else if(visited[neighbor] && dfsvisited[neighbor]){
      return true;
    }
  }

  dfsvisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, vector<int>> adj;

    // Build adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, dfsvisited, visited, adj)) {
                return 1;
            }
        }
    }

    return 0;

}
