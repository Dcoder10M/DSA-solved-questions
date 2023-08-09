class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=0;
        int curr=-69,count=0;
        for(int i=0;i<nums.size();i++){
            if(curr!=nums[i]){
                curr=nums[i];
                count=1;
                nums[x]=nums[i];
                x++;
            }else{
                count++;
                if(count==2){
                    nums[x]=nums[i];
                    x++;
                }
            }
        }return x;
    }
};