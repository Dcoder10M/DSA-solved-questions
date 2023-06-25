class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        stack<vector<int>> st;
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(intervals[i]);
            }else{
                vector<int> temp=st.top();
                if(temp[1]>intervals[i][0]){
                    ans++;
                }else{
                    st.push(intervals[i]);
                }
            }
        }return ans;
    }
};