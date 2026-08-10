class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        vector<vector<int>>adj(m*n); 
        vector<int>indegree(40201,0); 
        int dx[4] = {-1,0,1,0}; 
        int dy[4] = {0,-1,0,1}; 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int hash = n*i+j; 
                for(int r = 0; r<4; r++)
                {
                    int n_i = i+dx[r]; 
                    int n_j = j+dy[r]; 
                    if(n_i>=0 && n_i<m && n_j>=0 && n_j<n && matrix[n_i][n_j]>matrix[i][j])
                    {
                        int hash2 = n*n_i+n_j; 
                        adj[hash].push_back(hash2); 
                        indegree[hash2]++; 
                    }

                }
            }
        }
        queue<int>q; 
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(indegree[n*i+j]==0)q.push(n*i+j); 
            }
        }

        int ans = 0; 
        while(!q.empty())
        {
            int sz = q.size(); 
            ans++; 
            for(int i=0; i<sz; i++)
            {
                int curr = q.front();
                q.pop(); 
                for(auto &x: adj[curr])
                {
                    indegree[x]--; 
                    if(indegree[x]==0)q.push(x); 
                }
                
            }
        }

        return ans; 
        

    }
};
