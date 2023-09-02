class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int fact=1;
        vector<int> num;
        for(int i=1;i<=n;i++){
            if(i!=n)
            fact=fact*i;
            num.push_back(i);
        }
        string ans="";
        while(num.size()>0){
            ans.push_back('0'+num[k/fact]);
            num.erase(num.begin() + k/fact);
            if(num.size()==0)break;
            k=k%fact;
            fact=fact/num.size();
        }return ans;
    }
};