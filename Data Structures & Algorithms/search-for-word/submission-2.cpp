class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board, string word)
    {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!=word[0])return false; 
        char curr = word[0]; 
        string rem = word.substr(1); 
        if(rem=="")
        {
            return true; 
        }
        board[x][y] = '*'; 
        bool check =  dfs(x+1,y,board,rem) || dfs(x,y+1,board,rem) || dfs(x,y-1,board,rem) || dfs(x-1,y,board,rem); 
        board[x][y] = curr; 
        return check; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(); 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dfs(i,j,board, word))
                {
                    return true; 
                }
            }
        }

        return false; 
    }
};
