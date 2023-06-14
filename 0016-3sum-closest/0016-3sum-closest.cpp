class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=1e8;
        int diff=1e8;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int x=0;x<n-2;x++){
            int l=x+1,r=n-1;
            int sum=nums[x]+nums[l]+nums[r];
            while(l<r){
                sum=nums[x]+nums[l]+nums[r];
                if(diff>abs(target-sum)){
                    ans=sum;
                    diff=abs(target-sum);
                }
                if(sum==target){
                    return target;
                }else if(sum>target){
                    r--;
                }else l++;
            }
        }return ans;
    }
};