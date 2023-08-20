class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        set<char> m;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                ans++;
                m.clear();
            }
            m.insert(s[i]);
        }return ans+1;
    }
};