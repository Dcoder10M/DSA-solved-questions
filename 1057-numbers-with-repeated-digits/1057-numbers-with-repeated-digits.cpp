class Solution {
public:
    int dp[11][1<<11][3];
    int solve(int ind,int mask,int tight,string num){
        if(ind==num.size())return 1;
        if(dp[ind][mask][tight]!=-1)return dp[ind][mask][tight];
        int limit=9;
        if(tight)limit=num[ind]-'0';
        int ans=0;
        for(int digit=0;digit<=limit;digit++){
            if(digit==0 && mask==0){
                ans+=solve(ind+1,mask,0,num);
                continue;
            }
            if((mask&(1<<digit))==0){
                ans+=solve(ind+1,mask|(1<<digit),(tight&&(digit==limit)),num);
            }
        }return dp[ind][mask][tight]=ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return n-solve(0,0,1,s)+1;
    }
};