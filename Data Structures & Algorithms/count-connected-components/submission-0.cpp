class Solution {
public:
    void dfs(int start, vector<vector<int>>&adj, vector<int>&vis)
    {
        vis[start] = 1; 
        for(auto x: adj[start])
        {
            if(!vis[x])
            {
                dfs(x, adj, vis); 
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
            
            vector<vector<int>>adj(n); 
            for(auto &x: edges)
            {
                adj[x[0]].push_back(x[1]); 
                adj[x[1]].push_back(x[0]); 
            }

            vector<int>vis(n); 
            int count = 0; 
            for(int i=0; i<n; i++)
            {
                if(!vis[i])
                {
                    count++; 
                    dfs(i, adj, vis); 
                }
            }

            return count; 
    }
};
