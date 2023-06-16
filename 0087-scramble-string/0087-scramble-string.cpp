class Solution {
    unordered_map<string, int>mp;
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!= s2.length()) return false;

        if(s1.length() == 0 && s2.length() == 0) return true;

        if(s1.compare(s2) == 0) return true;

        if(s1.length() <= 1) return false;
        // Map Wala Kaam;
        string temp = s1;
        temp.push_back(' ');
        temp += s2;

        if(mp.find(temp) != mp.end()) return mp[temp];
        int n = s1.length();
        bool flag = false;

        for(int i = 1; i < n; i++){
            if(isScramble(s1.substr(0, i),s2.substr(n-i)) == true && 
            isScramble(s1.substr(i), s2.substr(0, n-i)) == true){
                flag = true;
                break;
            }
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) == true&& isScramble(s1.substr(i), s2.substr(i)
            ) == true){
                flag = true;
                break;
            }
        }
        return mp[temp] = flag;
    }
};