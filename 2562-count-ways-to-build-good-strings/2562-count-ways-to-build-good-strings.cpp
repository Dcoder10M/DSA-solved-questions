class Solution {
public:

int m=1e9+7;

long long int sumi(int n, int zero, int one, vector<long long int> &dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n]%m;
    long long int a=0,b=0;
    if(n>=zero) a=sumi(n-zero,zero,one,dp)%m;
    if(n>=one) b=sumi(n-one,zero,one,dp)%m;
    return dp[n]=(a+b)%m;
}

    int countGoodStrings(int low, int high, int zero, int one) {
        long long int ans=0;
        vector<long long int> dp(high+1,-1);
        for(int i=low;i<=high;i++){
            ans+=sumi(i,zero,one,dp)%m;
        }
        return ans%m;
    }
};