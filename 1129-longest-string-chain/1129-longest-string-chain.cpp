class Solution {
public:
    bool compare(string &a,string &b){
        if(a.size()!=b.size()+1)return false;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        if((i==a.size()||i==a.size()-1) && j==b.size())return true;
        return false;
    }
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        vector<int> ans;
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        for(auto i:words){
            cout<<i<<" ";
        }
        vector<int> dp(n+1,1);
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                    }
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
            }
        }
        return mx;
    }
};