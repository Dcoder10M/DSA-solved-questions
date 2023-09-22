class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind=0;
        int n1=s.size(),n2=t.size();
        
        if(n1==0)return true;
        for(int i=0;i<n2;i++){
            if(s[ind]==t[i])ind++;
            if(ind==n1)return true;
        }return false;
    }
};