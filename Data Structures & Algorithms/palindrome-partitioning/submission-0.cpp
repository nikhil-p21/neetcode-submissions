class Solution {
public:
    vector<vector<string>>ans; 
    bool ispalindrome(string &a, int i, int j)
    {
        while(i<=j)
        {
            if(a[i]!=a[j])return false; 
             i++; j--; 
        }

        return true; 
    }
    void generate(string &s, vector<string>&curr, int index)
    {
        int n = s.size(); 
        if(index==n)
        {
            ans.push_back(curr); 
            return; 
        }

        for(int i=index; i<n; i++)
        {
            if(ispalindrome(s,index,i))
            {

                curr.push_back(s.substr(index, i-index+1)); 
                generate(s,curr,i+1); 
                curr.pop_back(); 
            }
           
           
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr; 
        generate(s, curr, 0); 

        return ans; 
    }
};
