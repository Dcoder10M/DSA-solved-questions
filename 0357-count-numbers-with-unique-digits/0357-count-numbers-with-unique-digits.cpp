class Solution {
public:
    int dp[10][1<<11][3][3][3];
    int solve(int ind,int mask,int tight,int lz,int repeated,string &s){
        if(ind==s.size()){
            if(repeated)return 1;
            return 0;
        }
        if(dp[ind][mask][tight][lz][repeated]!=-1)return dp[ind][mask][tight][lz][repeated]; 
        int limit=9;
        int ans=0;
        if(tight)limit=s[ind]-'0';
        if(lz){
            ans+=solve(ind+1,mask,0,1,0,s);
        }
        for(int i=0;i<=limit;i++){
            if(lz && i==0)continue;
            if((mask>>i)&1){
                ans+=solve(ind+1,mask,(tight&&(i==limit)),0,1,s);
            }else{
                ans+=solve(ind+1,mask|(1<<i),(tight&&(i==limit)),0,repeated,s);
            }
        }return dp[ind][mask][tight][lz][repeated]=ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        string s="";
        int temp=pow(10,n);
        while(n--){
            s.push_back('9');
        }
        memset(dp,-1,sizeof(dp));
        // cout<<s<<endl;
        return temp-solve(0,0,1,1,0,s);
    }
};