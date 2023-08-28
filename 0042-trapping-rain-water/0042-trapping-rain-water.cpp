class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int lmax=0,rmax=0;
        int ans=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(lmax<height[left])lmax=height[left];
                else ans+=lmax-height[left];
                left++;
            }
            else{
                if(rmax<height[right])rmax=height[right];
                else ans+=rmax-height[right];
                right--;
            }
        }return ans;
    }
};