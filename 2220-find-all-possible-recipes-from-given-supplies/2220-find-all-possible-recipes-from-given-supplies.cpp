class Solution {
public:
    unordered_map<string,bool> cookable;
    unordered_map<string, vector<string>> adj;
    unordered_map<string,bool> visited;
    bool dfs(string node)
    {
        if(visited[node]) return cookable[node];
        visited[node]= true;
        if(cookable.find(node)!=cookable.end())
            return cookable[node];
        if(adj[node].size()==0) 
            return cookable[node]=false; 
        for(auto i: adj[node])
            if(!dfs(i))
                return cookable[node]=false;
        return cookable[node]=true;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
        int n=recipes.size();
        
        for(int i=0;i<n;i++)
            for(auto j: ingredients[i])
                adj[recipes[i]].push_back(j);
        for(auto i:supplies) 
            cookable[i]=true;
        vector<string> ans;
        for(int i=0;i<n;i++)
            if(dfs(recipes[i])) 
                ans.push_back(recipes[i]);
        return ans;
    }
};