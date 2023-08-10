class Solution {
public:
    long long singleNumber(vector<int>& nums) {
        int op=0;
        for(auto i:nums){
            if(i==INT_MIN)op++;
        }   if(op==1)return INT_MIN;
        op=0;
        map<long long,long long> m;
        for(long long i=0;i<31;i++){
            long long temp=1<<i;
            for(auto j:nums){
                j=abs(j);
                if((temp&j)!=0)
                m[i]++;
            }
        }
        long long ans=0;
        for(long long i=0;i<31;i++){
            if(m[i]%3==1){
                ans+=1<<i;
            }
        }
        long long curr=0;
        for(long long i=0;i<nums.size();i++){
            if(nums[i]==ans)curr++;
        }
        if(curr==1)
        return ans;
        return -1*ans;    
    }
};