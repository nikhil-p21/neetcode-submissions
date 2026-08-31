class Solution {
public:
    int decode(string &s , int index, vector<int>&dp)
    {
        if(index==s.size())return 1; 
        if(s[index]=='0')return 0; 
        if(dp[index]!=-1)return dp[index]; 
        int ans = decode(s, index+1, dp); 
        if(index+1 < s.size())
        {
            string curr = s.substr(index, 2); 
            if(stoi(curr)<=26)ans+=decode(s, index+2, dp); 
        }

        return dp[index] = ans; 
        
    }
    int numDecodings(string s) {
        int index = 0; 
        vector<int>dp(101, -1); 
        return decode(s, index, dp); 
    }
};
