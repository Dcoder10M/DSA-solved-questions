class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        set<string> s;
        for(auto i:wordList)s.insert(i);
        s.erase(begin);
        queue<pair<string,int>> q;
        q.push({begin,1});
        while(!q.empty()){
            string temp=q.front().first;
            int curr=q.front().second;
            q.pop();
            for(int i=0;i<temp.size();i++){
                char og=temp[i];
                for(char c='a';c<='z';c++){
                    if(og==c)continue;
                    temp[i]=c;
                    if(s.find(temp)!=s.end()){
                        if(temp==end)return curr+1;
                        q.push({temp,curr+1});
                        s.erase(temp);
                    }
                }temp[i]=og;
            }
        }return 0;
    }
};