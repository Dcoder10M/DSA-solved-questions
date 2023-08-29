class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int> suf(n+1,0);
        int curr=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='Y')curr++;
            suf[i]=curr;
        }
        curr=0;
        int ans=INT_MAX;
        int ret=0;
        for(int i=0;i<n;i++){
            if(ans>suf[i]+curr){
                ans=suf[i]+curr;
                ret=i;
            }   
            if(s[i]=='N')curr++;
        }
        if(ans>curr){
            return n;
        }
        return ret;
    }
};