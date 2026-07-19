class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size(); 
        vector<int>my_triplets(3,INT_MIN); 

        for(auto &x: triplets)
        {
            if(x[0]<=target[0] && x[1]<=target[1] && x[2]<=target[2])
            {
                my_triplets[0] = max(my_triplets[0], x[0]); 
                my_triplets[1] = max(my_triplets[1], x[1]); 
                my_triplets[2] = max(my_triplets[2], x[2]); 
            }
        }

        return (my_triplets[0]==target[0] && my_triplets[1]==target[1] && my_triplets[2]==target[2]); 
    }

};
