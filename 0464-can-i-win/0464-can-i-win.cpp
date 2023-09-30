class Solution {
public:
    int dp[1<<21];
    bool canIWin(int M, int T) 
  {
    int sum = M*(M+1)/2; 
    memset(dp,-1,sizeof(dp));
    if (T < 2) return true;
    else if (sum < T) return false;
    else if (sum == T) return M%2;
    else return dfs(M, T, 0);
  }
  bool dfs(int M, int T, int k) 
  {
      if(dp[k]!=-1)return dp[k];
      if(T<=0)return false;
      for(int i=1;i<=M;i++){
          if((k&(1<<i))==0 && !dfs(M,T-i,k|(1<<i))){
              return dp[k]=true;
          }
      }return dp[k]=false;     
  }
};