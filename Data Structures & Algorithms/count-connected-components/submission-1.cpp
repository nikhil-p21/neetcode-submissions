class DSU{
    private:
        vector<int>parent; 
        vector<int>rank; 
    public:
        DSU(int n)
        {
            parent.resize(n); 
            rank.resize(n); 
            for(int i=0; i<n; i++)
            {
                parent[i] = i; 
            }
        }

        int find(int n)
        {
            if(parent[n]==n)return n;
            else return parent[n] = find(parent[n]); 

        }

        bool union_nodes(int a, int b)
        {
            int root_a = find(a); 
            int root_b = find(b); 
            if(root_a==root_b)return false; 

            if(rank[root_a]<rank[root_b])
            {
                swap(root_a, root_b); 
            }
            parent[root_b] = root_a; 
            rank[root_a]+=rank[root_b]; 

            return true; 
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n); 
         int cmp = n; 
         for(auto &x: edges)
         {
            if(dsu.union_nodes(x[0], x[1]))cmp--; 
         }
         return cmp; 
    }
};
