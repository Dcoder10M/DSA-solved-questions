class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) {
        int ans=1;
        map<int,int> m;
        for(int i=arr.size()-1;i>=0;i--){
            if(m.find(arr[i]+k)==m.end()){
                m[arr[i]]=1;
            }else{
                m[arr[i]]=1+m[arr[i]+k];
            }
            ans=max(ans,m[arr[i]]);
        }return ans;
    }
};