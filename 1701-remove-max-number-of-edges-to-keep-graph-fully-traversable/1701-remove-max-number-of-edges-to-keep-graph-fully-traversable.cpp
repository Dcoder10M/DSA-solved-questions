class Solution {
public:
    class dsu{
        public:
        int n=0;
        vector<int> par,size;
        dsu(int sz){
            n=sz+1;
            par.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)par[i]=i;
        }
        int findPar(int node){
            if(par[node]==node)return node;
            return par[node]=findPar(par[node]);
        }
        void unionBySize(int a,int b){
            int ap=findPar(a);
            int bp=findPar(b);
            if(ap==bp)return;
            if(size[ap]>size[bp]){
                par[bp]=ap;
                size[ap]+=size[bp];
            }else{
                par[ap]=bp;
                size[bp]+=size[ap];
            }
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu g1(n);
        dsu g2(n);
        int ans=0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                if(g1.findPar(edges[i][1])==g1.findPar(edges[i][2])){
                    ans++;
                    continue;
                }
                 g1.unionBySize(edges[i][1],edges[i][2]);
                 g2.unionBySize(edges[i][1],edges[i][2]);    
            }
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==2){
                if(g2.findPar(edges[i][1])==g2.findPar(edges[i][2])){
                    ans++;
                    continue;
                }
                g2.unionBySize(edges[i][1],edges[i][2]);    
            }
            if(edges[i][0]==1){
                if(g1.findPar(edges[i][1])==g1.findPar(edges[i][2])){
                    ans++;
                    continue;
                }
                g1.unionBySize(edges[i][1],edges[i][2]);  
            }
        }
        cout<<g1.size[g1.par[1]]<<endl;
        cout<<g2.size[g2.par[1]]<<endl;
        if(g1.size[g1.findPar(1)]!=n || g2.size[g2.findPar(1)]!=n)return -1;
        
        
        return ans;
    }
};