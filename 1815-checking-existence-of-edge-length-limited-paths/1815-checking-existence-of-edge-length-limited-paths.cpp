class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    }
    class dsu{
        int n=0;
        vector<int> par,size;
        public:
        dsu(int sz){
            n=sz+1;
            par.resize(n,1);
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
                size[ap]+=size[bp];
                par[bp]=ap;
            }else{
                size[bp]+=size[ap];
                par[ap]=bp;
            }
        }
    };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& a, vector<vector<int>>& queries) {
        int temp=0;
        for(auto &i:queries){
            i.push_back(temp++);
        }
        sort(queries.begin(),queries.end(),comp);
        sort(a.begin(),a.end(),comp);
        dsu ds(n);
        if(queries.size()==0)return {};
        vector<bool> ans(queries.size(),false);
        int j=0;
        for(int i=0;i<queries.size();i++){
            int curr=queries[i][2];
            // cout<<curr<<endl;
            while(j<a.size() && a[j][2]<curr){
                // cout<<a[i][0]<<" "<<queries[i][1]<<endl;
                ds.unionBySize(a[j][0],a[j][1]);
                j++;
            }
            // cout<<ds.findPar(queries[i][0])<<" "<<ds.findPar(queries[i][1])<<endl;
            if(ds.findPar(queries[i][0])==ds.findPar(queries[i][1])){
                ans[queries[i][3]]=1;
            }
        }return ans;
    }
};