#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool bfs(int node, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adj) {
    unordered_map<int, int> parent;
    queue<int> q;
    
    q.push(node);
    visited[node] = true;
    parent[node] = -1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int neighbor : adj[front]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = front;
                q.push(neighbor);
            } else if (parent[front] != neighbor) {
                
                return true;
            }
        }
    }

    return false;
}

bool dfs(int node,int parent, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adj) {
    visited[node] = true;

    for(int neighbor: adj[node]){
        if(!visited[neighbor]){
            bool ans = dfs(neighbor,node,visited,adj);
            if(ans){
                return true;
            }
        }
        else if(neighbor != parent){
            return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, vector<int>> adj;

    // Build adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // if (bfs(i, visited, adj)) {
            //     return "Yes";
            // }
            if (dfs(i,-1, visited, adj)) {
                return "Yes";
            }
        }
    }

    return "No";
}
