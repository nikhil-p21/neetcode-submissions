class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(); 
        stack<int>s; 
        vector<int>ans(n,0); 
        for(int i=0; i<temperatures.size(); i++)
        {
            int curr_temp = temperatures[i]; 
            while(!s.empty() && temperatures[s.top()]<curr_temp)
            {
                int ind = s.top(); 
                s.pop(); 
                ans[ind] = (i-ind); 
            }
            s.push(i); 
        }

        return ans; 
    }
};
