class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> mp1, mp2;
        for(auto ch : s1){
            mp1[ch]++;
        } 
        int low = 0, high = 0;
        while(high < s2.size()){
            mp2[s2[high]]++;
            if(high - low + 1 == len){
                if(mp1 == mp2) return true;
                mp2[s2[low]]--;
                if(mp2[s2[low]] == 0) mp2.erase(s2[low]);
                low++;
            }
            high++;
        }
        return false;
    }
};