class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size(); 
        int pick = 0; 
        int skip = 0; 
        for(int x: nums)
        {
            int next_rob = skip+x; 
            int next_skip = max(pick, skip); 
            pick = next_rob; 
            skip = next_skip; 
        }

        return max(pick, skip); 
        
    }
};
