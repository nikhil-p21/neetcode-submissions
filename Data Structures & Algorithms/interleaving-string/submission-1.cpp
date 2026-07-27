#include <bits/stdc++.h>
class Solution {
public:
    int dp[101][101]; 
    bool generate(string &s1, string &s2, string &s3, int i, int j)
    {
        if(i==s1.size() && j==s2.size())return true; 

        int k = i+j; 
        bool x= false; 
        bool y= false; 
        if(dp[i][j]!=-1)return dp[i][j]; 
        if(i<s1.size() && s1[i]==s3[k])
        {
            x = generate(s1,s2,s3,i+1,j); 
        }

        if(j<s2.size() && s2[j]==s3[k])
        {
            y = generate(s1,s2,s3,i,j+1); 
        }
        dp[i][j] = x || y; 
        return dp[i][j]; 
    }
    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size()+s2.size()!=s3.size())return false; 
        string curr = ""; 
        int i=0,j=0; 
        memset(dp,-1,sizeof(dp)); 
        return generate(s1,s2,s3,i, j); 
    }
};
