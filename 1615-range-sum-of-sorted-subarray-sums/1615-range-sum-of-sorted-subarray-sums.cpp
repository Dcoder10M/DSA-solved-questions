class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        left--;
        right--;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int cnt=0;
        int ans=0;
        while(cnt<=right){
            int mn=pq.top()[0];
            int index=pq.top()[1];
            pq.pop();
            index++;
            if(cnt>=left){
                ans=(ans+mn)%mod;
            }
            if(index<n){
                mn+=nums[index];
                pq.push({mn,index});
            }
            cnt++;
        }
        return ans;
    }   
};