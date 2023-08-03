class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n=s.size();
        map<char,int> last;
        for(int i=0;i<n;i++)last[s[i]]=i;
        stack<char> st;
        map<char,int> in;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                in[s[i]]++;
            }else{
                while(!st.empty() && st.top()>s[i] && i<last[st.top()]&& !in[s[i]]){
                    in[st.top()]--;
                    st.pop();
                }
                if(in[s[i]]==0){
                    st.push(s[i]);
                    in[s[i]]++;
                }
            }
        }while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }reverse(ans.begin(),ans.end());
        return ans;
    }
};