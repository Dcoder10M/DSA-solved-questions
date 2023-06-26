class Solution {
public:
    string largestOddNumber(string nums) {
        int i;
        for(i=nums.size()-1;i>=0;i--){
            if((nums[i]-'0')%2==1)break;
        }return nums.substr(0,i+1);
    }
};