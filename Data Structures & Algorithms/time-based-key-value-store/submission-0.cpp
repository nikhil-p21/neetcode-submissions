class TimeMap {
public:
    unordered_map<string , vector<pair<int,string>>>store; 
    TimeMap() {
        
    }
    string search_bin(vector<pair<int,string>>&temp, int timestamp)
    {
        int r = temp.size()-1, l = 0; 
        string ans = ""; 
        while(l<=r)
        {
            int mid = (l+r)/2; 
            if(temp[mid].first == timestamp)
            { 
                return temp[mid].second; 
            }
            else if(temp[mid].first<timestamp)
            {
                ans = temp[mid].second; 
                l = mid+1; 

            }
            else
            {
                r = mid-1; 
            }
        }
        return ans; 
    }
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value}); 
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)!=store.end())
        {
            return search_bin(store[key], timestamp); 
        }
        return ""; 
    }
};
