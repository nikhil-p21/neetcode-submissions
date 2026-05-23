class Solution {
public:
    vector<vector<int>>ans; 
    void solve(vector<int>&nums,int target, vector<int>&curr, int start)
    {
        if(target<0)
        {
            return; 
        }
        if(target==0)
        {
            
            ans.push_back(curr); 
            return; 
        }
        for(int i=start; i<nums.size(); i++)
        {
            if(target<0)break; 

            curr.push_back(nums[i]); 
            solve(nums, target-nums[i], curr, i); 
            curr.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr; 
        // sort(nums.begin(), nums.end()); 
        solve(nums, target, curr, 0); 
       
        return ans;
    }
};
