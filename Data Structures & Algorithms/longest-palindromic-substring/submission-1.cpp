class Solution {
public:
    int max_len = 0, start_index = 0; 
    void calc(string &s, int left, int right)
    {
        int n = s.size(); 
        while(left>=0 && right<n && s[left]==s[right])
        {
            left--;
            right++;
        }
        int curr_len = right-left-1; 
        if(curr_len>max_len)
        {
            start_index = left+1; 
            max_len = curr_len; 
        }
    }
    string longestPalindrome(string s) {
        
        int n = s.size(); 
        if(n==1)return s; 
        for(int i=0; i<n-1; i++)
        {
            calc(s,i,i); 
            calc(s,i,i+1); 
        }
        
        return s.substr(start_index, max_len); 
    }
};
