class Solution {
public:
    int dp[1001][1001];
    int solve(int n,int curr,int copied){
        if(curr==n)return 0;
        if(curr>n)return 1e8;
        if(dp[curr][copied]!=-1)return dp[curr][copied];
        int ans=1e8;
        if(curr!=copied)
        ans=2+solve(n,curr+curr,curr);
        if(copied!=0)
        ans=min(ans,1+solve(n,curr+copied,copied));
        return dp[curr][copied]=ans;
    }
    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,1,0);
    }
};