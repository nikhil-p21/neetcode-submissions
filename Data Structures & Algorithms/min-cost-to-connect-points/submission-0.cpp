class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        vector<bool>vis(n,false); 
        vector<int>min_dist(n,INT_MAX); 
        min_dist[0] = 0; 
        int cost = 0; 
        for(int steps=0; steps<n; steps++)
        {
            int u = -1; 
            for(int i=0; i<n; i++)
            {
                if(!vis[i] && (u==-1 || min_dist[i]<min_dist[u]))
                {
                    u = i; 
                }
            }

            cost+=min_dist[u]; 
            vis[u] = true; 

            for(int v=0; v<n; v++)
            {
                if(!vis[v])
                {
                    int weight = abs(points[v][0]-points[u][0])+abs(points[u][1]-points[v][1]); 
                    min_dist[v] = min(min_dist[v],weight); 
                }
            }
        }

        return cost; 
    }
};
