
class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(101, vector<int>(101,0)); 
        dp[0][0] = 1; 
        int m = s1.size(), n =s2.size(); 
        if(m+n!=s3.size())return false; 
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 && j==0)continue; 
                else if(i==0)dp[i][j] = (dp[i][j-1]&&(s3[i+j-1]==s2[j-1])); 
                else if(j==0)dp[i][j] = (dp[i-1][j]&&(s3[i+j-1]==s1[i-1])); 
                else dp[i][j] = (dp[i][j-1]&&(s3[i+j-1]==s2[j-1])) || (dp[i-1][j]&&(s3[i+j-1]==s1[i-1]));
            }
        }

        return dp[m][n]; 

    }
};
