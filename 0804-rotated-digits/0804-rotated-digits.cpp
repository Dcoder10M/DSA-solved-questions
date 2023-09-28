class Solution {
public:
    int dp[6][3][3][3];
    int solve(int ind,int tight,int leading_zero,string &s,vector<int> &digit,bool change){
        if(ind==s.size()){
            if(change)return 1;
            return 0;
        }
        if(dp[ind][tight][leading_zero][change]!=-1)return dp[ind][tight][leading_zero][change];
        int limit=9;
        if(tight)limit=s[ind]-'0';
        int ans=0;
        if(leading_zero){
            ans+=solve(ind+1,0,1,s,digit,change);
        }
        for(int i=0;i<digit.size();i++){
            if(digit[i]>limit)break;
            if(leading_zero && digit[i]==0){
                continue;
            }
            if(digit[i]==2 ||digit[i]==5 ||digit[i]==6 ||digit[i]==9 )
            ans+=solve(ind+1,(tight&&(limit==digit[i])),0,s,digit,1);
            else ans+=solve(ind+1,(tight&&(limit==digit[i])),0,s,digit,change);
        }return dp[ind][tight][leading_zero][change]=ans;
    }
    int rotatedDigits(int n) {
        string s=to_string(n);
        vector<int> digit={0,1,2,5,6,8,9};
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1,s,digit,0);
    }
};