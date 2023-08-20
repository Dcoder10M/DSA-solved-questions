class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        map<char,int> m;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(m[s[i]]>0){
                ans++;
                m.clear();
            }
            m[s[i]]=1;
        }return ans+1;
    }
};