class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size(); 
        int sum_gas = accumulate(gas.begin(), gas.end(), 0); 
        int sum_cost = accumulate(cost.begin(), cost.end(), 0); 
        if(sum_gas<sum_cost)return -1; 
        int total = 0; 
        int start = 0; 
        for(int i=0; i<n-1; i++)
        {
            total += (gas[i]-cost[i]); 
            if(total<0)
            {
                total = 0; 
                start = i+1; 
            }

        }
        if(start==n-1)return (gas[n-1]-cost[n-1]>=0)?start:-1; 
        return start; 

        
    }
};
