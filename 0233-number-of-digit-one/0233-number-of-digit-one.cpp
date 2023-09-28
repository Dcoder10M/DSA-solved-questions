class Solution {
public:
    int dp[11][2][2][1000];
    int solve(int ind,int tight,int leading_zero,int one_count,string &s){
        if(ind==s.size())return one_count;
        if(dp[ind][tight][leading_zero][one_count]!=-1)return dp[ind][tight][leading_zero][one_count];
        int ans=0;
        int limit=9;
        if(tight)limit=s[ind]-'0';
        if(leading_zero){
            ans+=solve(ind+1,0,1,one_count,s);
        }
        for(int i=0;i<=limit;i++){
            if(i==0 && leading_zero){continue;}
            if(i==1)
            ans+=solve(ind+1,(tight&&(i==limit)),0,one_count+1,s);
            else ans+=solve(ind+1,(tight&&(i==limit)),0,one_count,s);
        }return dp[ind][tight][leading_zero][one_count]=ans;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1,0,s);
    }
};