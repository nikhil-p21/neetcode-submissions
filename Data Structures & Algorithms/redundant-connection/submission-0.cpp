class DSU{

    public:
        vector<int>parent; 
        vector<int>sz; 

    DSU(int n)
    {
        parent.resize(n+1); 
        sz.resize(n+1,1); 
        for(int i=1; i<=n; i++)
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
        if(root_a==root_b)return false; 
        if(sz[root_a]>sz[root_b])swap(root_a,root_b); 
        parent[root_a] = root_b; 
        sz[root_b]+=sz[root_a]; 
        return true; 
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        DSU my_dsu(n); 
        for(auto &x : edges)
        {
            if(!my_dsu.unite(x[0],x[1]))return {x[0],x[1]}; 
        }

        return {}; 
    }
};
