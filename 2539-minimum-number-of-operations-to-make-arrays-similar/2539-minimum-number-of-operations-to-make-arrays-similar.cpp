class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> o1,o2,e1,e2;
        int i;
        for(i = 0; i < nums.size(); i++){
            if(nums[i]&1){
                o1.push_back(nums[i]);
            }else{
                e1.push_back(nums[i]);
            }
            if(target[i]&1){
                o2.push_back(target[i]);
            }else{
                e2.push_back(target[i]);
            }
        }
        sort(o1.begin(),o1.end());
        sort(o2.begin(),o2.end());
        sort(e1.begin(),e1.end());
        sort(e2.begin(),e2.end());
        long long int ans = 0;
        for(i = 0; i < e1.size(); i++){
            ans += abs(e1[i]-e2[i]);
        }
        for(i = 0; i < o1.size(); i++){
            ans += abs(o1[i]-o2[i]);
        }
        return ans/4;
    }
};