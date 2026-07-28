class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>mapping; 
        int n = position.size(); 
        for(int i=0; i<n; i++)
        {
            mapping.push_back({position[i], speed[i]}); 
        }

        sort(mapping.begin(), mapping.end(), [](pair<int,int>&a, pair<int,int>&b)
        {
            return a.first<b.first; 
        }); 

        stack<float>s; 
        int ans = 0; 
        for(auto &x: mapping)
        {
            float dis = (float)target-(float)x.first; 
            float speed = (float)x.second; 
            float time = dis/speed; 
            while(!s.empty() && s.top()<=time)
            {
                s.pop(); 
            }
            s.push(time); 
        }

        return s.size(); 
    }
};
