class Solution {
    public:
    string minWindow(string s, string t) {
      
      vector<int> v(128,0);
        int count =t.size(),minl=INT_MAX,inii=0,j=0;
      for(auto i: t)
      v[i]++;

       for(int i=0;i<s.size();i++){
            if(v[s[i]]>0) count--;
            v[s[i]]--;

            while(count==0){
                    if(minl>i-j+1){
                        minl=i-j+1;
                        inii=j;
                    }
                    v[s[j]]++;
                    if(v[s[j]]>0) count++;
                    j++;
            }
       }
       return minl==INT_MAX? "":s.substr(inii,minl);
    }
};