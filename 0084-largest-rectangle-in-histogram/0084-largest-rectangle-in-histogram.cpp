typedef long long ll;

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        ll ans=0;
        stack<int> s;
        int n=nums.size();
        vector<ll> mxr(n),mxl(n),mnr(n),mnl(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                s.pop();
            }
            if(s.empty()){
                mxl[i]=-1;
            }else mxl[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<nums[i]){
                s.pop();
            }
            if(s.empty()){
                mxr[i]=n;
            }else mxr[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                s.pop();
            }
            if(s.empty()){
                mnl[i]=-1;
            }else mnl[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty()){
                mnr[i]=n;
            }else mnr[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++){
            ll temp=nums[i]*(mnr[i]-mnl[i]-1);
            ans=max(ans,temp);
        }return ans;
    }
};