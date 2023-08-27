class Solution {
public:
    int dp[400][500];
    int solve(int ind,vector<int>& days,vector<int>& costs,int upto){
        if(ind==days.size())return 0;
        if(dp[ind][upto]!=-1)return dp[ind][upto];
        int ans=INT_MAX;
        ans=min(
            {costs[0]+solve(ind+1,days,costs,days[ind]),
            costs[1]+solve(ind+1,days,costs,days[ind]+6),
            costs[2]+solve(ind+1,days,costs,days[ind]+29)
            });
        if(upto>=days[ind]){
            ans=min(ans,solve(ind+1,days,costs,upto));
        }return dp[ind][upto]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs,0);
    }
};