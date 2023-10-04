class Solution {
public:
    vector<bool> row,col,dia1,dia2;
    int nn;
    bool isValid(int x,int y){
        if(row[x] || col[y] || dia1[nn+x-y] || dia2[x+y])return false;
        return true;
    }
    void solve(int ind,int n,vector<vector<string>> &ans,vector<string> &temp){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(ind,i)){
                temp[ind][i]='Q';
                row[ind]=1;
                col[i]=1;
                dia1[n+ind-i]=1;
                dia2[ind+i]=1;
                solve(ind+1,n,ans,temp);
                row[ind]=0;
                col[i]=0;
                dia1[n+ind-i]=0;
                dia2[ind+i]=0;
                temp[ind][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        nn=n;
        row.resize(n+1,0);
        col.resize(n+1,0);
        dia1.resize(2*n+1,0);
        dia2.resize(2*n+1,0);
        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.'));
        solve(0,n,ans,temp);
        return ans;
    }
};