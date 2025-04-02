#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfsUtil(int node, vector<int> adj[], vector<bool>& vis, vector<int>& dfs) { // Pass dfs by reference
        vis[node] = true;
        dfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsUtil(it, adj, vis, dfs);
            }
        }
    }

public:
    vector<int> dfsofGraph(int v, vector<int> adj[]) {
        vector<bool> vis(v, false);
        vector<int> dfs;
        dfsUtil(0, adj, vis, dfs);
        return dfs;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V]; // Adjacency list

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    Solution obj;
    vector<int> result = obj.dfsofGraph(V, adj);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;  // Add a newline for better formatting
    return 0; // Add return statement
}