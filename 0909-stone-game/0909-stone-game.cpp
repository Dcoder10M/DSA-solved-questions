class Solution {
public:
    // turn: 1->alice , 0->bob 
    int dp[501][501][2];
    bool solve(vector<int>& piles,int l, int r,int tn){
        if(l>r) return 0;
        if(dp[l][r][tn]!=-1) return dp[l][r][tn]; // if case has already been encountered

        int alice=0,bob=0;
        int left,right;
        if(tn==1){
            left = piles[l]+ solve(piles,l+1,r,0);        
            right = piles[r]+ solve(piles,l,r-1,0);
            return dp[l][r][tn]=max(left,right); //storing the result in dp for alice
        }
        else{
            left = piles[l]+ solve(piles,l+1,r,1);        
            right = piles[r]+ solve(piles,l,r-1,1);
            return dp[l][r][tn]=max(left,right); //storing the result in dp for bob
        }
        
        return 0;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        return solve(piles,0,piles.size()-1,1);
    }
};