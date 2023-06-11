class Solution {
public:

    int minMutation(string start, string end, vector<string>& bank) {
        string trav="ACGT";
        set<string> s;
        for(auto i:bank)s.insert(i);
        queue<string> q;
        int ans=0;
        if(start==end)return 0;
        q.push(start);
        while(!q.empty()){
            int x=q.size();
            while(x--){
                string temp=q.front();
                q.pop();
                for(int i=0;i<temp.size();i++){
                    char og=temp[i];
                    for(int j=0;j<4;j++){
                        char c=trav[j];
                        temp[i]=c;
                        if(s.find(temp)!=s.end()){
                            if(temp==end)return ans+1;
                            q.push(temp);
                            s.erase(temp);
                        }
                    }temp[i]=og;
                }
            }ans++;
        }return -1;
    }
};