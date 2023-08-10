class Solution {
public:
    //check function to check if "t" is a substring in curr_s substring 
    bool check(map<char,int> &map_s,map<char,int> &map_t){
        for(auto &itr: map_t){
            if(map_s[itr.first] < itr.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size() < t.size() ){
            return "";
        }
        if(s == t) return s;
        int resulti = 0;
        int anslen  = INT_MAX;
        int i=0;
        int j=0;
        int n = s.size();
        map<char,int> map_t;
        map<char,int> map_s;
        for(auto &itr:t){ //feed string 't' into map_t
            map_t[itr]++;
        }
        //sliding window
        while(j<n){
            map_s[s[j]]++;
            while(check(map_s,map_t)){
                if(j-i+1 <= anslen){
                    anslen = j-i+1;
                    resulti = i;
                }
                map_s[s[i]]--;
                if(map_s[s[i]]==0) map_s.erase(s[i]);
                i++;
            }
            j++;
        }
        if(anslen==INT_MAX) return "";
        return s.substr(resulti,anslen);
    }
};