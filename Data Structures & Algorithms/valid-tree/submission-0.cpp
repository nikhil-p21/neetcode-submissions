class DSU{
    private:
        vector<int>parent; 
        vector<int>sz; 
    public:
        DSU(int n)
        {
            sz.resize(n, 1); 
            parent.resize(n); 
            for(int i=0; i<n; i++)
            {
                parent[i] = i; 
            }
        }
        int find(int a)
        {
            if(parent[a]==a)return a; 
            return parent[a] = find(parent[a]); 
        }
        bool unite(int a, int b)
        {
            int root_a = find(a); 
            int root_b = find(b); 
            if(root_a==root_b)return true; 
            if(sz[root_a]>sz[root_b])
            {
                swap(root_a, root_b); 
            }
            parent[root_a] = root_b; 
            sz[root_b]+=sz[root_a]; 
            return false; 

        }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        DSU my_dsu(n); 
        if(edges.size()!=n-1)return false; 
        for(auto &x: edges)
        {
            if(my_dsu.unite(x[0], x[1]))return false; 
        }
        return true; 

    }
};
