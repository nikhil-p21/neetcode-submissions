class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses); 
        for(auto &x : prerequisites)
        {
            adj[x[1]].push_back(x[0]); 
            indegree[x[0]]++; 
        }
        queue<int>q; 
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)q.push(i); 
        }
        int count = 0; 
        while(!q.empty())
        {
            int curr = q.front(); 
            q.pop(); 
            count++; 

            for(auto x: adj[curr])
            {
                indegree[x]--; 
                if(indegree[x]==0)q.push(x); 
            }
        }

        return (count == numCourses); 


    }
};
