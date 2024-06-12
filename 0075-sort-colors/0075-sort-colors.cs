public class Solution {
    public void SortColors(int[] nums) {
        int low=0,high=nums.Length-1,mid=0;
        while(low<high && mid<=high){
            if(nums[mid]==0){
                nums[mid]=nums[low];
                nums[low++]=0;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                nums[mid]=nums[high];
                nums[high--]=2;
            }
            if(low>mid)mid=low;
        }
    }
}