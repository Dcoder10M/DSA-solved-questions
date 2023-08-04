class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> arr;
        int n=plantTime.size();
        for(int i=0;i<n;i++){
            arr.push_back({growTime[i],plantTime[i]});
        } 
        sort(arr.rbegin(),arr.rend());
        int ans=0;
        int curr=0;
        for(int i=0;i<n;i++){
            ans=max(ans,curr+arr[i].second+arr[i].first);
            curr=curr+arr[i].second;
        }return ans;
    }
};