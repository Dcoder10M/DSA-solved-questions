class Solution {
public:
    int dp[32][2][2];
    int helper(int pos, int tight, int prv_digit, string &binary){
        if(pos==binary.size()){
            return 1;
        }
        if(dp[pos][tight][prv_digit]!=-1) return dp[pos][tight][prv_digit];
        int low=0;
        int high;
        if(tight) high=binary[pos]-'0';
        else high=1;
        int ans=0;
        for(int i=low;i<=high;i++){
            if(i==1 && prv_digit==1){ // if previous digit is 1 then we can,t take another 1
                continue;
            }
            else{
                if(i==high && tight){
                    ans+=helper(pos+1,1,i,binary);
                }
                else{
                    ans+=helper(pos+1,0,i,binary);
                }
            }

        }
        return dp[pos][tight][prv_digit]=ans;
      
    }

    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        string binary="";
        while(n){
            if(n%2==1){
                binary.push_back('1');          
            }
            else {
                binary.push_back('0');
            }
            n/=2;
        }
        reverse(binary.begin(),binary.end());
        int ans=helper(0,1,0,binary);

        return ans; 
    }
};