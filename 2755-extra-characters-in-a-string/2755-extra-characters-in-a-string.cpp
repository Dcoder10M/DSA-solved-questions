class Solution {
public:
    int solve(int ind,string &s,set<string> &m,vector<int> &dp){
        if(ind==s.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        string temp="";
        int ans=INT_MAX;
        for(int i=ind;i<s.size();i++){
            temp.push_back(s[i]);
            if(m.find(temp)!=m.end()){
                ans=min(solve(i+1,s,m,dp),ans);
            }
        }
        ans=min(ans,1+solve(ind+1,s,m,dp));
        return dp[ind]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> m;
        for(auto i:dictionary)m.insert(i);
        vector<int> dp(s.size(),-1);
        return solve(0,s,m,dp);
    }
};