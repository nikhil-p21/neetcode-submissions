class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size(); 
        for(int i=0; i<n; i++)
        {

            int curr_gas = gas[i]; 
            int pos = i; 
            while(true)
            {
                curr_gas -= cost[pos]; 
                if(curr_gas<0)break; 
                pos = (pos+1)%n; 
                curr_gas+=gas[pos]; 
                if(pos==i)return pos; 
            }
        }

        return -1; 
    }
};
