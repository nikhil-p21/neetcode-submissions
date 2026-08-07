class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;  
        int n = s.size(); 
        if(n==0)return 0; 
        int i=0, j=0; 
        int ans = 1; 
        while(j<n)
        {
            freq[s[j]]++; 
            
            while(freq[s[j]]>1)
            {
                freq[s[i]]--; 
                if(freq[s[i]]==0)freq.erase(s[i]); 
                i++; 

            }

            ans = max(ans, j-i+1); 
            j++; 
            
            
        }

        return ans; 
    }
};
