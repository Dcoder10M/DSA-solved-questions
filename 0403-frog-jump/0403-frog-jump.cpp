class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> m;
        m[1]={1};
        for(int i=1;i<stones.size();i++){
            for(auto j:m[stones[i]]){
                m[stones[i]+j].insert(j);
                m[stones[i]+j+1].insert(j+1);
                m[stones[i]+j-1].insert(j-1);
            }
        }return m[stones.back()].size()>0;
    }
};