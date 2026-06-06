class Solution {
    const vector<int>dir = {-1,0,1,0,-1}; 
public:
   
    void solve(vector<vector<char>>& board) {
        int m = board.size(); 
        int n = board[0].size(); 
        queue<pair<int,int>>q; 
        for(int i=0; i<m; i++)
        {
            if(board[i][0]=='O')
            {
                board[i][0] = '#'; 
                q.push({i,0}); 
            }
            if(board[i][n-1]=='O')
            {
                board[i][n-1] = '#'; 
                q.push({i,n-1}); 
            }
        }
        for(int j=1; j<n; j++)
        {
            if(board[0][j]=='O')
            {
                board[0][j] = '#'; 
                q.push({0,j}); 
            }
            if(board[m-1][j]=='O')
            {
                board[m-1][j] = '#'; 
                q.push({m-1,j}); 
            }
        }

        while(!q.empty())
        {
            pair<int,int>curr = q.front(); 
            int r = curr.first, c = curr.second; 
            q.pop(); 
            for(int d=0; d<4; d++)
            {
                int nr = r+dir[d]; 
                int nc = c+dir[d+1]; 
                if(nr>=0 && nr<m && nc>=0 && nc<n)
                {
                    if(board[nr][nc]=='O')
                    {
                        board[nr][nc] = '#'; 
                        q.push({nr,nc}); 
                    }
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O')board[i][j] = 'X'; 
                if(board[i][j]=='#')board[i][j] = 'O'; 
            }
        }
        
    }
};
