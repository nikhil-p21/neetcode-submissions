

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(char &x: tasks)
        {
            freq[x]++; 
        }

        priority_queue<int>pq; 
        for(auto &x: freq)
        {
            pq.push(x.second); 
        }

        int cycles = 0; 
        while(!pq.empty())
        {
            int time = 0; 
            vector<int>temp; 
            for(int i=0; i<=n; i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top()-1); 
                    pq.pop(); 
                    time++; 
                }
            }

            for(int x: temp)
            {
                if(x>0)pq.push(x); 
            }

            cycles+=(pq.empty())?time:n+1; 
        }

        return cycles; 
       
    }
};
