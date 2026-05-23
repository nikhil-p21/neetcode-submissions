class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size(); 
        if(n<m)return false; 
        vector<int>freq1(26,0); 
        for(char x: s1)
        {
            freq1[x-'a']++; 
        }
        vector<int>freq2(26,0); 
        
        int i=0, j=0; 
        while(j<n)
        {
            freq2[s2[j]-'a']++; 
            while(j-i+1>m && i<=j)
            {
                freq2[s2[i]-'a']--; 
                i++;
                
            }
           
            if(freq1==freq2)return true; 
            j++; 
        }
        return false; 

        
    }
};