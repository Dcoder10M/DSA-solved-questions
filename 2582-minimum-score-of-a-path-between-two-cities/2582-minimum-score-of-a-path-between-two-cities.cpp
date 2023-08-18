class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUlt(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUlt(parent[node]);
    }

    void findUnion(int u, int v){
        int paru = findUlt(u);
        int parv = findUlt(v);
        if(paru == parv) return;
        if(size[paru] > size[parv]){
            parent[parv] = paru;
            size[paru]++;
        }
        else if(size[paru] > size[parv]){
            parent[paru] = parv;
            size[parv]++;
        }
        else{
            parent[parv] = paru;
            size[paru]++;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        for(auto it : roads){
            ds.findUnion(it[0], it[1]);
        }
        int temp = ds.findUlt(1), ans = INT_MAX;
        for(auto it : roads){
            int ult_u = ds.findUlt(it[0]), ult_v = ds.findUlt(it[1]);
            if(ult_u == temp || ult_v == temp)
                ans = min(ans, it[2]);
        }
        return ans;
    }
};