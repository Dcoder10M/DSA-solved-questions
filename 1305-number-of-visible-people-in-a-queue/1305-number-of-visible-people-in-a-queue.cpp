class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n=h.size();
        vector<int>ans;
        stack<int>s;
        s.push(h[n-1]);  // last element stack me push karo
        ans.push_back(0);
        for(int i=n-2;i>=0;i--){    //array ko last se iterate karo
            int c=0;
            while(!s.empty() && s.top()<h[i]){   //stack me jo elements chote hai usko pop karo or counter badhao
                s.pop();
                c++;
            }
            if(!s.empty())c++;   //non empty stack ke liye add 1 in counter
            s.push(h[i]);
            ans.push_back(c);
        }
// count = [no. of pops + (for empty stack -> 0 , for non empty stack -> 1)]
        reverse(ans.begin(),ans.end());   
        return ans;
    }
};