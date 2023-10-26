class Solution {
public:
    int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        long long ans=0;
        vector<int> bits(31,0);
        for(auto num:nums){
            for(int i=30;i>=0;i--){
                if(((1<<i)&num)!=0)bits[i]++;
            }
        }
        while(k--){
            long long temp=0;
            for(int i=30;i>=0;i--){
                if(bits[i]){
                    temp=(temp+(1<<i))%mod;
                    bits[i]--;
                }
            }
            ans=(ans+(temp*temp)%mod)%mod;
        }return ans;
    }
};