class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end()); 
        int ans = 0; 
        for(int x: s)
        {
            if(s.count(x-1)==0)
            {
                int curr = x;
                int streak = 0; 
                while(s.count(curr))
                {
                    streak++; 
                    curr++; 
                }
                ans = max(ans, streak); 
            }

        }

        return ans; 
    }
};
