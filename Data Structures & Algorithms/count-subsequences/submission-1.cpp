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
        
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, 0)); 
        int m = s.size(), n = t.size(); 
        
        for(int i=0; i<=m; i++)
        {
            dp[i][0] = 1; 
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j]; 
                }
                else 
                {
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }

        return dp[m][n]; 
    }
};
