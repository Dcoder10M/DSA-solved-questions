class Solution {
public:
    int binary_search(vector<int> &arr,int curr,int left,int right){
        if(left==right-1)return right;
        int mid=left+right;
        mid=mid/2;
        if(arr[mid]>=curr){
            right=mid;
        }else{
            left=mid;
        }
        return binary_search(arr,curr,left,right);
    }
    int lis(vector<int> &arr){
        if(arr.size()==0)return 0;
        vector<int> curr;
        curr.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            int mx=curr[curr.size()-1];
            if(arr[i]>mx){
                curr.push_back(arr[i]);
            }
            else{
                int ind=binary_search(curr,arr[i],-1,curr.size());
                if(ind>=0 && ind<curr.size())
                curr[ind]=arr[i];
            }
        }
        return curr.size();
    }
    int maxPathLength(vector<vector<int>>& arr, int k) {
        int xx=arr[k][0],yy=arr[k][1];
        sort(arr.begin(),arr.end(),[](vector<int> &a,vector<int> &b){
            return ((a[0]<b[0])||(a[0]==b[0] && (a[1]>b[1])));
        });
        vector<int> left,right;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]<xx && arr[i][1]<yy){
                left.push_back(arr[i][1]);
            }
            if(arr[i][0]>xx && arr[i][1]>yy){
                right.push_back(arr[i][1]);
            }
        }
        int ans=1;
        ans+=lis(left)+lis(right);
        return ans;
    }
};