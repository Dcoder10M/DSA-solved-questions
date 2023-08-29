class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n=start.size();
        vector<int> dp(n+1,0);
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({start[i],end[i],profit[i]});
        }
        sort(end.begin(),end.end());
        sort(jobs.begin(),jobs.end(),comp);
        for(int i=0;i<n;i++){
            int ind=upper_bound(end.begin(),end.end(),jobs[i][0])-end.begin();
            // if(start[i]==6)cout<<ind;
            dp[i+1]=max(jobs[i][2]+dp[ind],dp[i]);
        }
        for(int i=0;i<=n;i++)cout<<dp[i]<<endl;
        return dp[n];
    }
};