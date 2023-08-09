class Solution {
public:
    int solve(vector<int>& arr,int mid){
        int ans=0;
        for(auto i:arr)if(i>=mid)ans++;
        return ans;
    }
    int hIndex(vector<int>& arr) {
        int low=-1,high=1e8;
        while(low+1<high){
            int mid=(low+high)/2;
            if(solve(arr,mid)>=mid)low=mid;
            else high=mid;
        }return low;
    }
};