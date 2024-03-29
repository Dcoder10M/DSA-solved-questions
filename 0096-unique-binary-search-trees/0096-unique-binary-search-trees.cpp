class Solution {
public:
    int dp[100];
    int solve(int n){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=(solve(i-1)*solve(n-i));
        }return dp[n]=ans;
    }
    int numTrees(int n) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            ans+=(solve(i-1)*solve(n-i));
        }return ans;
    }
};