class Solution {
private:
    int solver(vector<int>& rods, int i, int diff, int dp[][10001]){
        if(i == rods.size()){
            if(diff == 0) return 0;
            return -6000;
        }
        if(dp[i][diff+5000] != -1) return dp[i][diff+5000];

        int option1 = solver(rods,i+1,diff,dp);
        int option2 = rods[i] + solver(rods,i+1,diff+rods[i],dp);
        int option3 = rods[i] + solver(rods,i+1,diff-rods[i],dp);

        return dp[i][diff+5000] = max(option1,max(option2,option3));
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int dp[21][10001];
        memset(dp,-1,sizeof(dp));
        return solver(rods,0,0,dp)/2;
    }
};