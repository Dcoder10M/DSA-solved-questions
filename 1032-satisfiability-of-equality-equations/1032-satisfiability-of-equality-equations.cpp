class Solution {
public:
    class dsu{
        vector<int> parent,size;
        public:
        dsu(int n){
            parent.resize(n+1,0);
            size.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findPar(int node){
            if(parent[node]==node)return node;
            return parent[node]=findPar(parent[node]);
        }
        void unionSize(int a,int b){
            int ulta=findPar(a);
            int ultb=findPar(b);
            if(ulta==ultb)return;
            if(size[ulta]>size[ultb]){
                parent[ultb]=ulta;
                size[ulta]+=size[ultb];
            }else{
                parent[ulta]=ultb;
                size[ultb]+=size[ulta];
            }
        }
    };
    bool equationsPossible(vector<string>& equations) {
        dsu ds(30);
        sort(equations.begin(),equations.end());
        for(auto i:equations){
            int a=i[0]-'a';
            int b=i[3]-'a';
            if(i[1]=='='){
                ds.unionSize(a,b);
            }
        }
        for(auto i:equations){
            int a=i[0]-'a';
            int b=i[3]-'a';
            if(i[1]=='!'){
                if(ds.findPar(a)==ds.findPar(b))return false;
            }
        }
        
        return true;
    }
};