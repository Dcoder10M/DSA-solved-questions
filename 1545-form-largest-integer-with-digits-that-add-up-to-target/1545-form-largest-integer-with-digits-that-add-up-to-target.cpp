class Solution {
public:
    string MAX(string &a,string &b){
        if(a.find("0")!=string::npos) return b;
        if(b.find("0")!=string::npos) return a;
        if(a.size()>b.size())return a;
        return b;
    }
    string f(vector<int>& cost, int target,int i,vector<vector<string>>&dp){
        if(target==0 && i==cost.size())return "";
        if(target<0 || i==cost.size()) return "0";
        if(dp[target][i]!="-1")return dp[target][i];
        string op1=to_string(i+1)+f(cost,target-cost[i],0,dp);
        string op2=f(cost,target,i+1,dp);
        return dp[target][i]=MAX(op1,op2);
    }
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<string>>dp(target+1,vector<string>(10,"-1"));
        return f(cost,target,0,dp);
    }
};