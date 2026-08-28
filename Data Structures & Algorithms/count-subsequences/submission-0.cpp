class Solution {
public:
    int recur(string &s, string &t, int start, int j, vector<vector<int>>&dp)
    {
        if(j==t.size())
        {
            return 1; 
        }
        if(start>=s.size())return 0; 
        int local_ans = 0; 
        if(dp[start][j]!=-1)return dp[start][j];
        for(int i=start; i<s.size(); i++)
        {
            if(s[i]==t[j])
            {
                local_ans+=recur(s,t,i+1,j+1, dp); 
            }
        }
        return dp[start][j] = local_ans;  
        
    }
    int numDistinct(string s, string t) {
        string curr = ""; 
        int i=0, j=0; 
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1)); 
        return recur(s, t, i, j, dp); 
    }
};
