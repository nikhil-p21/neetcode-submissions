class Solution {
public:
    unordered_map<string, int>dp; 
    int calculate(vector<int>&nums, int sum , int target, int index)
    {
        if(index==nums.size() && sum==target)
        {
            return 1; 
        }
        if(index>=nums.size())return 0; 
        string state = to_string(index)+'_'+to_string(sum); 
        if(dp.find(state)!=dp.end())return dp[state]; 
        int a = calculate(nums, sum+nums[index] , target, index+1);
        int b = calculate(nums, sum-nums[index], target, index+1); ; 
        return dp[state] = a+b; 
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear(); 
        return calculate(nums, 0 , target, 0); 
    }
};
