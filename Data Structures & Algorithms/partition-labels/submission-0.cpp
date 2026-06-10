class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(); 
        vector<int>last(26, 0); 

        for(int i=0; i<n; i++)
        {
            last[s[i]-'a'] = i; 
        }

        vector<int>ans; 
        int last_idx = 0; 
        int curr_max = 0; 
        for(int i=0; i<n; i++)
        {
            curr_max = max(curr_max, last[s[i]-'a']);

            if(i==curr_max)
            {
                ans.push_back(i-last_idx+1); 
                last_idx = i+1; 
            }
        } 
        return ans; 
    }
};
