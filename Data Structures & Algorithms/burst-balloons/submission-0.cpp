class Solution {
public:
    int burst(vector<int>&nums, int i, int j, vector<vector<int>>&dp)
    {
        if(i>j)return 0; 
        if(dp[i][j]!=-1)return dp[i][j]; 

        int max_coins = INT_MIN; 

        for(int k=i; k<=j; k++)
        {
            max_coins = max(max_coins, burst(nums, i, k-1, dp)+burst(nums, k+1, j,dp)+nums[i-1]*nums[k]*nums[j+1]); 
        }

        return dp[i][j] = max_coins; 
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); 
        nums.push_back(1); 
        int n = nums.size(); 
        vector<vector<int>>dp(n, vector<int>(n,-1)); 
        return burst(nums,1, n-2, dp); 
    }
};
