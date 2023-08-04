class Solution {
public:
    int longestDecomposition(string text) {
        int i=0,j=text.size()-1;
        string a="",b="";
        int ans=0;
        while(i<j){
            a.push_back(text[i]);
            b=text[j]+b;
            if(a==b){
                ans++;
                a="";
                b="";
                if(i==j-1){
                    return ans*2;
                }
            }
    
            i++;j--;
        }
        // if(i==j)return 2*ans +1;
        return 2*ans+1;
    }
};