struct TrieNode{
    TrieNode* next[26] = {}; 
    string word = ""; 
}; 

class Trie
{
    public: 
        TrieNode* root; 
        Trie()
        {
            root = new TrieNode(); 
        }

        void insert(string word)
        {
            TrieNode* curr = root; 
            for(char &x : word)
            {
                if(!curr->next[x-'a'])
                {
                    curr->next[x-'a'] = new TrieNode(); 
                }
                curr = curr->next[x-'a']; 
            }

            curr->word = word; 
            
        }
};

class Solution {
public:

    void dfs(int x, int y, vector<vector<char>>&board, TrieNode* root, vector<string>&ans)
    {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]=='*')return; 
        char curr = board[x][y]; 
        TrieNode* next = root->next[curr-'a']; 
        if(next==NULL)return;
        if(next->word!="")
        {
            ans.push_back(next->word); 
            next->word = ""; 
        }
        board[x][y] = '*'; 
        dfs(x+1,y,board,next,ans); 
        dfs(x,y+1,board,next,ans); 
        dfs(x,y-1,board,next,ans);
        dfs(x-1,y,board,next,ans); 
        board[x][y] = curr; 
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie my_trie; 
        
        for(string &x: words)
        {
            my_trie.insert(x); 
        }

        TrieNode* root = my_trie.root; 

        int m = board.size(), n = board[0].size(); 
        vector<string>ans; 
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                dfs(i,j,board,root,ans); 
            }
        }

        return ans; 
    }
};
