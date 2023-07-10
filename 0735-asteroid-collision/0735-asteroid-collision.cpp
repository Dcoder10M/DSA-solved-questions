class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(s.empty()){s.push(a[i]);continue;}
            if(!s.empty() && s.top()<0){s.push(a[i]);continue;}
            if(a[i]>=0){s.push(a[i]);continue;}
            while(!s.empty() && s.top()>=0 && s.top()<abs(a[i])){
                s.pop();
            }
            if(s.empty()){
                s.push(a[i]);
            }else if(abs(a[i])==s.top()){
                s.pop();
            }else if(s.top()<0) s.push(a[i]);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }reverse(ans.begin(),ans.end());
        return ans;
    }
};