class Solution {
public:
    int ladderLength(string A, string B, vector<string> &C) {
        set<string> s;
        for(auto i:C)s.insert(i);
        queue<pair<string,int>> q;
        q.push({A,1});
        s.erase(A);
        while(!q.empty()){
            string temp=q.front().first;
            int curr=q.front().second;
            q.pop();
            for(int i=0;i<temp.size();i++){
                char og=temp[i];
                for(char j='a';j<='z';j++){
                    if(temp[i]==j)continue;
                    temp[i]=j;
                    if(s.find(temp)!=s.end()){
                        if(temp==B)return curr+1;
                        s.erase(temp);
                        q.push({temp,curr+1});
                    }temp[i]=og;
                }
            }
        }return 0;
    }
};