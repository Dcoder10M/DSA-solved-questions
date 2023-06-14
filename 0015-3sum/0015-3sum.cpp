class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> s;
        for(int x=0;x<n-2;x++){
            int l=x+1,r=n-1;
            int sum=nums[x]+nums[l]+nums[r];
            while(l<r){
                sum=nums[x]+nums[l]+nums[r];
                if(sum==0){
                    s.insert({nums[x],nums[l],nums[r]});
                    l++,r--;
                }else if(sum>0){
                    r--;
                }else l++;
            }
        }for(auto i:s){ans.push_back(i);}return ans;
    }
};