class Solution {
public:

     bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis, vector<int>& pathvis,vector<int> & safe){
         vis[node]=1;
         pathvis[node]=1;
          for(auto it : graph[node]){
              if(vis[it]!=1){ 
                   if(dfs(it,graph,vis,pathvis,safe)==true){ 
                        //  safe[it]=0; 
                        return true;
                   }
              }
              else if(pathvis[it]==1){ 
                    // safe[it]=0;   
                    return true;
              }
          }
        //  safe[node]=1;   
         pathvis[node]=0;
         return false;   
     }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n+1,0);  
        vector<int> pathvis(n+1,0); 
        vector<int> safe(n+1,0); 
        vector<int> safenode; 
        for(int i=0;i<n;i++){
             if(vis[i]!=1){
                 dfs(i,graph,vis,pathvis,safe);
             }
        }
        for(int i=0;i<n;i++){
            if(!(pathvis[i]==1 && vis[i]==1)){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};




// class Solution {
// public:
//     bool dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &path){
//         vis[node]=1;
//         path[node]=1;
//         for(auto i:adj[node]){
//             if(!vis[i]){
//                 if(dfs(i,adj,vis,node)==true){
//                     return true;
//                 }
//             }else if(path[i]==1){
//                 return true;
//             }
//         }
//         path[node]=0;
//         return false;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int> vis(n,0);
//         vector<int> path(n,0);
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 dfs(i,graph,vis,path);
//             }
//         }vector<int> ans;
//         for(int i=0;i<n;i++){
//             if(vis[i]==1 && path[i]==1)ans.push_back(i);
//         }return ans;
//     }
// };