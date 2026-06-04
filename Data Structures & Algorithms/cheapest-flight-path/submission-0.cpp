class Solution {
    const int INF = 1e9+7; 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,INF); 
        
        dis[src] = 0; 
        for(int i=0; i<=k; i++)
        {
            vector<int>temp = dis; 
            for(auto &flight : flights)
            {
                int u=flight[0], v= flight[1], w = flight[2]; 
                if(dis[u]==INF)continue; 
                temp[v] = min(temp[v] , dis[u]+w); 
            }
            dis = temp; 
        }

        return (dis[dst]==INF)?-1:dis[dst]; 
        
    }

    
};
