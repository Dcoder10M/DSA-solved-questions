class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int left_max=0,right_max=0;
        int i=0,j=height.size()-1;
        while(i<=j){
            if(height[i]<height[j]){
                left_max=max(left_max,height[i]);
                ans+=left_max-height[i];
                i++;
            }else{
                right_max=max(right_max,height[j]);
                ans+=right_max-height[j];
                j--;
            }
        }return ans;
    }
};