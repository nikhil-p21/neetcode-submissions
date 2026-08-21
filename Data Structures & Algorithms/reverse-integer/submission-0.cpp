class Solution {
public:
    int reverse(int x) {
        long long res = 0; 
        while(x!=0)
        {
            int curr_digit = x%10; 
            x/=10; 
            res = res*10+curr_digit; 
        }

        if(res>INT_MAX || res<INT_MIN)return 0; 
        return res; 
    }
};
