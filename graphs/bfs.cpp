#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    vector<int> bfsofGraph(int V, vector<int> adj[]){
        vector<bool> vis(V, false);
        vector<int> bfs;
        queue<int> q;

        vis[0] = true;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main(){
    int V,E;
    cin>> V>>E;
    vector<int> adj[V];

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;

    vector<int> result = obj.bfsofGraph(V, adj);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}