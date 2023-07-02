class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        set<int> remove;
        int x=0;
        for(int i=0;i<s.size();i++){
            if(x==0)remove.insert(i);
            if(s[i]=='('){
                x++;
            }else x--;
            if(x==0)remove.insert(i);
        }
        for(int i=0;i<s.size();i++){
            if(remove.find(i)==remove.end())ans.push_back(s[i]);
        }return ans;
    }
};