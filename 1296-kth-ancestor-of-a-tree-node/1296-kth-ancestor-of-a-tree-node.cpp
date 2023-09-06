class TreeAncestor {
public:
    vector<vector<int>> v;
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> par(n,vector<int>(20));
        for(int i=0;i<n;i++){
            par[i][0]=parent[i];
        }
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){
                if(par[i][j-1]==-1)par[i][j]=-1;
                else par[i][j]=par[par[i][j-1]][j-1];
            }
        }
        v=par;
    }
    
    int getKthAncestor(int node, int k) {
        int ans=node;
        for(int i=19;i>=0;i--){
            if(k & (1<<i)){
                ans=v[ans][i];
                if(ans==-1)return -1;
            }
        }return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */