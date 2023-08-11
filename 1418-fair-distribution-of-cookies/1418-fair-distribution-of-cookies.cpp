class Solution {
public:
    int ans1=INT_MAX;
    void solve(vector<int>&arr,int n,vector<int> &v,int k,int ind){
        if(ind==n){
            int ans=INT_MIN;
            for(int i=0;i<k;i++){
                ans=max(ans,v[i]);
            }
            ans1=min(ans,ans1);
            return;
        }
        for(int i=0;i<k;i++){
            v[i]+=arr[ind]; 
            solve(arr,n,v,k,ind+1);
            v[i]-=arr[ind];
        }
    }
    int distributeCookies(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> v(k,0);
        solve(arr,n,v,k,0);
        return ans1;
    }
};