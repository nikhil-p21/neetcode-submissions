class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        if len(nums)==1:
            return True
        rem = nums[0]
        for vals in nums:
            rem-=1
            if rem<0:
                return False
            rem = max(vals, rem)
            
        return True