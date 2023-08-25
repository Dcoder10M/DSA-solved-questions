class Solution {
public:
    int solve(int ind,vector<int>& arr,bool a,vector<vector<int>> &dp){
        if(ind==arr.size())return 0;
        if(dp[ind][a]!=INT_MIN)return dp[ind][a];
        if(a){
            int ans=INT_MIN;
            ans=arr[ind]+solve(ind+1,arr,0,dp);
            if(ind+1<arr.size())
            ans=max(ans,arr[ind]+arr[ind+1]+solve(ind+2,arr,0,dp));
            if(ind+2<arr.size())
            ans=max(ans,arr[ind]+arr[ind+1]+arr[ind+2]+solve(ind+3,arr,0,dp));
            return dp[ind][a]=ans;
        }else{
            int ans=INT_MAX;
            ans=-arr[ind]+solve(ind+1,arr,1,dp);
            if(ind+1<arr.size())
            ans=min(ans,-arr[ind]-arr[ind+1]+solve(ind+2,arr,1,dp));
            if(ind+2<arr.size())
            ans=min(ans,-arr[ind]-arr[ind+1]-arr[ind+2]+solve(ind+3,arr,1,dp));
            return dp[ind][a]=ans;
        }
    }
    string stoneGameIII(vector<int>& arr) {
        vector<vector<int>> dp(arr.size()+1,vector<int>(2,INT_MIN));
        int ans=solve(0,arr,1,dp);
        if(ans>0){
            return "Alice";
        }else if(ans==0){
            return "Tie";
        }else{
            return "Bob";
        }
    }
};