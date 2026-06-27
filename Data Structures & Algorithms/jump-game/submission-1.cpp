class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); 
        if(nums.size()==1)return true; 
        if(nums[0]==0)return false; 
        
        int goal = n-1; 
        int curr = n-2; 
        for(int i=curr; i>=0; i--)
        {
            int can_reach = nums[i]+i; 
            if(can_reach>=goal)
            {
                goal = i; 
            }
        }

        return (goal==0); 
    }
};
