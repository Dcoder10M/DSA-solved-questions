class Solution {
public:
    int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        long long ans=0;
        vector<int> bits(31,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<=30;j++){
                if(nums[i]&(1<<j)){
                    bits[j]++;
                }
            }
        }
        while(k--){
            long long temp=0;
            for(int i=0;i<=30;i++){
                if(bits[i]){
                    temp=temp|(1<<i);
                    bits[i]--;
                }
            }ans=(ans+(temp*temp)%mod)%mod;
        }
        return ans;
    }
};