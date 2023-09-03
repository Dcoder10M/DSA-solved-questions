class Solution {
public:
    int dp[11][11][11][20][2][2]; // dp[n][evencnt][oddcnt][rem][tight][leadingzero]
    int k;
    int solve(string &num,int n,int evencnt,int oddcnt,int rem,int tight,int leadingzero){
        // Base Case
        if(n==0){
            return (evencnt == oddcnt) & (rem==0);  
        }
        // memo
        if(dp[n][evencnt][oddcnt][rem][tight][leadingzero]!=-1) return dp[n][evencnt][oddcnt][rem][tight][leadingzero];
        int ub = tight?num[num.size()-n]-'0':9; // upper bound of digit
        int ans=0;
        // recursive
        for(int dig=0;dig<=ub;dig++){
            if(leadingzero && (dig==0)){
                ans += solve(num,n-1,0,0,0,0,1); // leading zero 
            }
            else ans += solve(num,n-1,evencnt + (!(dig&1)),oddcnt + (dig&1),(rem*10+dig)%k,tight & (dig==ub),0); // if dig is even => evencnt+1 else oddcnt+1
        }
        return dp[n][evencnt][oddcnt][rem][tight][leadingzero]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int K) {
        k = K;
        memset(dp,-1,sizeof(dp));
        low--;
        string l = to_string(low);
        int ans1 = solve(l,l.size(),0,0,0,1,1);
        memset(dp,-1,sizeof(dp));
        string r = to_string(high);
        int ans2 = solve(r,r.size(),0,0,0,1,1);
        return ans2-ans1;
    }
};