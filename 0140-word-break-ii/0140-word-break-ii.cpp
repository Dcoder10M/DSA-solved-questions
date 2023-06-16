class Solution {
public:
    unordered_set<string> m;
    void solve(int ind,string &s,vector<string> &ans,string temp){
        if(ind==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string ch=s.substr(ind,i-ind+1);
            if(m.find(ch)!=m.end()){
                solve(i+1,s,ans,temp+ch+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> ans;
        string temp="";
        m.clear();
        for(auto i:dict)m.insert(i);
        solve(0,s,ans,temp);
        return ans;
    }
};