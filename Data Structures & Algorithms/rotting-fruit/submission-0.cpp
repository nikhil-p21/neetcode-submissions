class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        queue<pair<int,int>>q; 
        int rotten = 0; 
        int empty = 0; 
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)empty++; 
                else if(grid[i][j]==2)
                {
                    q.push({i,j}); 
                    grid[i][j] = -1; 
                }
            }
        }
        int t = -1; 
        int dx[4] = {-1,0,1,0}; 
        int dy[4] = {0,1,0,-1}; 
        while(!q.empty())
        {
            int sz = q.size(); 
            rotten+=sz; 
            t++; 
            for(int i=0; i<sz; i++)
            {
                pair<int,int>curr= q.front(); 
                q.pop(); 
                int x = curr.first, y = curr.second; 
                for(int k=0; k<4; k++)
                {
                    int n_x = x+dx[k]; 
                    int n_y = y+dy[k]; 

                    if(n_x>=0 && n_x<m && n_y>=0 && n_y<n && grid[n_x][n_y]==1 && grid[n_x][n_y]!=-1)
                    {
                        q.push({n_x,n_y}); 
                        grid[n_x][n_y] = -1; 
                    }
                }
            }
        }
        int total_fruits = m*n - empty; 
        if(total_fruits==0)return 0; 
        return (rotten == total_fruits)?t:-1; 
    }
};
