class Solution {
public:
    int dp[12][2][2];
    int solve(string &R,int n,int tight,int leadingzero,vector<int> &digits){
        if(n==0)return 1;
        if(dp[n][tight][leadingzero]!=-1)return dp[n][tight][leadingzero];
        int ans=0;
        int limit=tight?(R[R.size()-n]-'0'):9;
        if(leadingzero){
            ans+=solve(R,n-1,0,1,digits);
        }

        for(int i=0;i<digits.size();i++){
            if(leadingzero && digits[i]==0)continue;
            if(digits[i]>limit)break;
            ans+=solve(R,n-1,(tight&&digits[i]==limit),0,digits);
        }return dp[n][tight][leadingzero]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string R=to_string(n);
        vector<int> dig;
        for(auto i:digits){
            dig.push_back(i[0]-'0');
            cout<<dig.back()<<endl;
        }
        memset(dp,-1,sizeof(dp));
        return solve(R,R.size(),1,1,dig)-1;
    }
};