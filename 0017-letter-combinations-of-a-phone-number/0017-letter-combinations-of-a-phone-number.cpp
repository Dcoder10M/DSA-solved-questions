class Solution {
public:
    void solve(int ind,string &digits,string temp,vector<string> &ans,map<int,vector<char>> &m){
        if(ind==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(auto i:m[digits[ind]]){
            temp.push_back(i);
            solve(ind+1,digits,temp,ans,m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        map<int,vector<char>> m;
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        vector<string> ans;
        string temp="";
        solve(0,digits,temp,ans,m);
        return ans;
    }
};