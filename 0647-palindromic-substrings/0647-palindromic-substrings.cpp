class Solution {
public:
    bool pal(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }return true;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int l=1;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                if(pal(s,i,i+l-1))ans++;
            }
        }return ans;
    }
};