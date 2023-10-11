class Solution {
public:
    int solve(int left,int right,vector<int> &nums,vector<vector<int>> &dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1)return dp[left][right];
        int c1=nums[left]-solve(left+1,right,nums,dp);
        int c2=nums[right]-solve(left,right-1,nums,dp);
        return dp[left][right]=max(c1,c2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        return solve(0,n-1,nums,dp)>=0;
    }
};