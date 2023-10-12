class Solution {
public:
    int addMinimum(string word) {
        int ans=0;
        int n=word.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                if(word[i]=='a'){st.push(word[i]);continue;}
                if(word[i]=='b'){ans++;st.push(word[i]);continue;}
                if(word[i]=='c'){ans+=2;st.push(word[i]);continue;}
            }
            if(word[i]=='b'){
                if(st.empty()){ans++;st.push(word[i]);continue;}
                if(st.top()=='a'){st.push(word[i]);continue;}
                if(st.top()=='b'){ans+=2;st.push(word[i]);continue;}
                if(st.top()=='c'){ans++;st.push(word[i]);continue;}
            }
            if(word[i]=='c'){
                if(st.empty()){ans+=2;st.push(word[i]);continue;}
                if(st.top()=='a'){ans++;st.push(word[i]);continue;}
                if(st.top()=='b'){st.push(word[i]);continue;}
                if(st.top()=='c'){ans+=2;st.push(word[i]);continue;}
            }
            if(word[i]=='a'){
                if(st.empty()){st.push(word[i]);continue;}
                if(st.top()=='b'){ans++;st.push(word[i]);continue;}
                if(st.top()=='a'){ans+=2;st.push(word[i]);continue;}
                if(st.top()=='c'){st.push(word[i]);continue;}
            }
        }
        if(word[n-1]=='a')ans+=2;
        if(word[n-1]=='b')ans++;
        return ans;
    }
};