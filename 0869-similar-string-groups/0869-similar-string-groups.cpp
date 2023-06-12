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
    int numSimilarGroups(vector<string>& strs) {
      int curr=0;
      map<string,int> m;
      for(auto i:strs){
          if(m.find(i)==m.end()){
              m[i]=curr++;
          }
      }  
      dsu ds(curr);
      int n=strs.size();
      for(int i=0;i<n-1;i++){
          for(int j=i+1;j<n;j++){
              string a=strs[i];
              string b=strs[j];
              if(a==b){
                  ds.unionSize(m[a],m[b]);
                  continue;
              }
              if(a.size()!=b.size())continue;
              int mm=a.size();
              int ind1=-1,ind2=-1;
              bool t=true;
                for(int k=0;k<mm;k++){
                    if(a[k]!=b[k]){
                        if(ind1==-1){
                            ind1=k;
                        }else if(ind2==-1){
                            ind2=k;
                        }else t=false;
                    }
                }
                if(!t)continue;
                if(ind2==-1)continue;
                ds.unionSize(m[a],m[b]);
          }
      }
      set<int> s;
      for(auto i:strs){
          s.insert(ds.findPar(m[i]));
      }return s.size();
    }
};