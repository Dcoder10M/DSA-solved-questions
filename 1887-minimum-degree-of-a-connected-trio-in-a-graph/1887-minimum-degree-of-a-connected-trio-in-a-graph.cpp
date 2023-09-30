class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> m(n+10,vector<bool>(n+10,0));
        vector<int> degree(n+1,0);

        for(auto i:edges){
            m[i[0]][i[1]]=1; m[i[1]][i[0]]=1;
            degree[i[0]]++;
            degree[i[1]]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(m[i][j]){
                    for(int k=j+1;k<=n;k++){
                        if(m[i][k] && m[j][k]){
                            ans=min(ans,degree[i]+degree[j]+degree[k]-6);
                        }
                    }
                }
            }
        }if(ans==INT_MAX)return -1;
        return ans;
    }
};