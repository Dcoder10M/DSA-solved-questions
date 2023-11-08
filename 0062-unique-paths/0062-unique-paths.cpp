class Solution {
public:
    int solve(int m,int n,vector<vector<int>> &dp){
        if(m<0 || n<0)return 0;
        if(m==0 && n==0)return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]=solve(m-1,n,dp)+solve(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        double res=1;
        int N=n+m-2;
        for(int i=1;i<n;i++){
            res=res*(i+m-1)/i;
        }return (int)res;
    }
};