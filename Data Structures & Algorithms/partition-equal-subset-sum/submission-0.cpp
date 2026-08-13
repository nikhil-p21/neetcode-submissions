class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for(int &x: nums)
        {
            sum+=x; 
        }

        if(sum&1)return false; 
        sum/=2; 
        
        vector<int>dp(sum+1,0); 
        dp[0] = 1; 
        for(int x: nums)
        {
            for(int s=sum; s>=1; s--)
            {
                if(s-x>=0)
                {
                    dp[s] |= dp[s-x]; 
                }
                
            }
        }

        return dp[sum]; 
    }
};
