class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>>graph; 
        vector<int>indegree(26,-1); 
        int unique_chars = 0; 
        for(string &word: words)
        {
            for(char c: word)
            {
                if(indegree[c-'a']==-1)
                {
                    indegree[c-'a'] = 0; 
                    unique_chars++; 
                }
            }
        }

        for(int i=0; i<words.size()-1; i++)
        {
            string w1 = words[i], w2 = words[i+1]; 
            bool prefix = true; 
            for(int j=0; j<min(w1.size(), w2.size()); j++)
            {
                if(w1[j]!=w2[j])
                {
                    graph[w1[j]].push_back(w2[j]); 
                    indegree[w2[j]-'a']++; 
                    prefix = false; 
                    break; 
                }
            }
            if(prefix && w1.size()>w2.size())return ""; 
        }

        queue<int>q; 
        for(int i=0; i<26; i++)
        {
            if(indegree[i]==0)q.push(i); 
        }
        string ans = ""; 
        while(!q.empty())
        {
            int curr = q.front(); 
            ans+=(curr+'a'); 
            q.pop(); 
            for(auto &nei: graph[curr+'a'])
            {
                indegree[nei-'a']--; 
                if(indegree[nei-'a']==0)q.push(nei-'a'); 
            }
        }
        if(ans.size()<unique_chars)return ""; 
        return ans; 
    }
};
