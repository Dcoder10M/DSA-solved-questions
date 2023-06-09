class Solution {
public:
    class dsu{
        vector<int> parent,size;
        public:
        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findPar(int node){
            if(parent[node]==node)return node;
            return parent[node]=findPar(parent[node]);
        }
        void unidsodks(int u,int v){
            int ult_u=findPar(u);
            int ult_v=findPar(v);
            if(ult_u==ult_v)return;
            if(size[ult_u]>size[ult_v]){
                parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }else{
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu ds(10000);
        for(auto i:edges){
            if(ds.findPar(i[0])==ds.findPar(i[1]))return {i[0],i[1]};
            ds.unidsodks(i[0],i[1]);
        }return {-1};
    }
};