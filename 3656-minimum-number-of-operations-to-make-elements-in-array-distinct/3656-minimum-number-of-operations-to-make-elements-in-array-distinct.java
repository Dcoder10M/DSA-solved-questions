class Solution {
    public int minimumOperations(int[] nums) {
        int ans=0;
        Map<Integer,Integer> m=new HashMap<>();
        // map<int,int> m
        for(int i=nums.length-1;i>=0;i--){
            if(m.containsKey(nums[i])){
                ans=i+1;
                break;
            }
            m.put(nums[i],1);
        }
        int ret=0;
        if(ans%3 != 0)ret++;
        ret+=ans/3;
        return ret;
    }
}