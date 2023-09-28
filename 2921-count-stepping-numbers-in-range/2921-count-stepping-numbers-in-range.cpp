class Solution {
public:
long long  mod=1e9+7;
    long long dp[200][2][2][13];
    long long solve(long long ind,long long tight,long long lz,long long prev,string &s){
        if(ind==s.size())return 1;
        if(dp[ind][tight][lz][prev]!=-1)return dp[ind][tight][lz][prev]%mod;
        long long ans=0;
        long long limit=9;
        if(tight)limit=s[ind]-'0';
        if(lz){
            ans=(ans+solve(ind+1,0,1,12,s))%mod;
        }
        for(long long i=0;i<=limit;i++){
            if(lz && i==0)continue;
            if(prev==12 || abs(prev-i)==1){
                ans=(ans+solve(ind+1,(tight&&(i==limit)),0,i,s))%mod;
            }
        }return dp[ind][tight][lz][prev]=ans%mod;
    }
    long long brute(string &s){
        for(long long i=0;i<s.size()-1;i++){
            long long a=s[i]-'0';
            long long b=s[i+1]-'0';
            if(abs(a-b)!=1)return 0;
        }return 1;
    }
    long long countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        long long ans=solve(0,1,1,12,high);
        memset(dp,-1,sizeof(dp));
        ans=(ans-solve(0,1,1,12,low)+mod)%mod;
        ans=(ans+brute(low))%mod;
        return ans%mod;
    }
};