class Solution {
public:
    int dp[101][101][101];
    int solve(int curr,int start,int end,vector<int> &box){
        if(start>end)return 0;
        if(dp[curr][start][end]!=-1)return dp[curr][start][end]; 
        int ans=((curr+1)*(curr+1)) + solve(0,start+1,end,box);
        for(int i=start+1;i<=end;i++){
            if(box[i]==box[start]){
                ans=max(ans,solve(0,start+1,i-1,box)+solve(curr+1,i,end,box));
            }
        }return dp[curr][start][end]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,boxes.size()-1,boxes);
    }
};