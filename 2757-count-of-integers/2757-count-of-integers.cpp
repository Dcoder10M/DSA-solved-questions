class Solution {
public:
    long long mod=1e9+7;
    long long dp[25][2][2][500];
    long long solve(string &R,long long n,long long tight,long long leadingzero,long long &min_sum,long long &max_sum,long long temp){
        if(temp>max_sum)return 0;
        if(n==0){
            if(temp>=min_sum && temp<=max_sum)return 1;
            return 0;
        }
        if(dp[n][tight][leadingzero][temp]!=-1)return dp[n][tight][leadingzero][temp];
        long long ans=0;
        long long limit=tight?(R[R.size()-n]-'0'):9;
        for(long long i=0;i<=limit;i++){
            if(leadingzero && i==0){
                ans=(ans+(solve(R,n-1,0,1,min_sum,max_sum,temp))%mod+mod)%mod;
            }
            else{
                ans=(ans+(solve(R,n-1,(tight && i==limit),0,min_sum,max_sum,temp+i))%mod+mod)%mod;
            }
        }return dp[n][tight][leadingzero][temp]=ans;
    }
    long long count(string num1, string num2, long long min_sum, long long max_sum) {
        memset(dp,-1,sizeof(dp));
        long long left=solve(num1,num1.size(),1,1,min_sum,max_sum,0);
        memset(dp,-1,sizeof(dp));
        long long right=solve(num2,num2.size(),1,1,min_sum,max_sum,0);
        long long temp=0;
        for(auto i:num1){
            temp+=(i-'0');
        }
        if(temp>=min_sum && temp<=max_sum)temp=1;
        else temp=0;
        return (right-left+temp+mod)%mod;
    }
};