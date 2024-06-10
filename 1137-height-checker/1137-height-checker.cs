public class Solution {
    public int HeightChecker(int[] heights) {
        List<int> list=new List<int>();
        foreach(var i in heights){
            list.Add(i);
        }
        list.Sort();
        int ans=0;
        for(int i=0;i<heights.Length;i++){
            if(heights[i]!=list[i])ans++;
        }
        return ans;
    }
}