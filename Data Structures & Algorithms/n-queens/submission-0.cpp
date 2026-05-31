class Solution {
private:
    unordered_set<int>cols; 
    unordered_set<int>pos_diag; 
    unordered_set<int>neg_diag; 
    vector<vector<string>>ans; 
    void solve(int row, int n, vector<string>&board)
    {
        if(row==n)
        {
            ans.push_back(board); 
            return; 
        }

        for(int col=0; col<n; col++)
        {
            if(cols.count(col) || pos_diag.count(row+col) || neg_diag.count(row-col))
            {
                continue;
            }

            board[row][col] = 'Q'; 
            cols.insert(col); 
            pos_diag.insert(row+col); 
            neg_diag.insert(row-col); 
            solve(row+1, n, board); 

            board[row][col] = '.'; 
            pos_diag.erase(row+col); 
            neg_diag.erase(row-col); 
            cols.erase(col); 
        }
       
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n,'.')); 
        solve(0, n , board); 
        return ans; 
    }
};
