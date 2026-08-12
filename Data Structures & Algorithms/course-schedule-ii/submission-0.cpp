class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses); 
        vector<int>indegree(numCourses, 0); 
        for(auto &x: prerequisites)
        {
            adj[x[1]].push_back(x[0]); 
            indegree[x[0]]++; 
        }
        queue<int>q; 
        vector<int>ans; 
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)q.push(i); 
        }

        while(!q.empty())
        {
            int curr = q.front(); 
            q.pop(); 
            ans.push_back(curr); 
            for(auto &nei: adj[curr])
            {
                indegree[nei]--; 
                if(indegree[nei]==0)q.push(nei); 
            }
        }

        return (ans.size()==numCourses)? ans: std::vector<int>{}; 
    }
};
