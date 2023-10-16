class Solution {
public:
    unordered_map<int,vector<int>> m;
    vector<int> vis;
    int solve(int node,vector<int> &arr){
        queue<pair<int,int>> q;
        q.push({node,0});
        vis[0]=1;
        while(!q.empty()){
            int x=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(x==arr.size()-1)return dist;
            if(!vis[x+1]){
                vis[x+1]=1;
                q.push({x+1,dist+1});
            }if(x>0 && !vis[x-1]){
                vis[x-1]=1;
                q.push({x-1,dist+1});
            }
            vector<int> temp=m[arr[x]];
            for(int i=temp.size()-1;i>=0;i--){
                if(!vis[temp[i]]){
                    vis[temp[i]]=1;
                    q.push({temp[i],dist+1});
                }
            }
            m[arr[x]].clear();
        }return -1;
    }
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }vis.resize(n,0);
        return solve(0,arr);
    }
};