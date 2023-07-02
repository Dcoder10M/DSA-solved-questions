class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums)sum+=i;
        if(sum%2==1)return false;
        sum=sum/2;
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
            for(int j=1;j<=sum;j++){
        for(int i=1;i<=n;i++){

                if(nums[i-1]==j)dp[i][j]=1;
                else if(j>=nums[i-1])
                dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                
                else dp[i][j]=dp[i-1][j];
            }
        }return dp[n][sum];
    }
};