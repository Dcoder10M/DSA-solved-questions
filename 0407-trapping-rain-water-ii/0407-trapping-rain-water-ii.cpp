class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({arr[i][j],i,j});
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
        int dx[]={1,0,0,-1};
        int dy[]={0,1,-1,0};
        while(!pq.empty()){
            int mx=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=x+dx[i];
                int nc=y+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    if(arr[nr][nc]>mx){
                        pq.push({arr[nr][nc],nr,nc});
                    }else{
                        ans+=mx-arr[nr][nc];
                        pq.push({mx,nr,nc});
                    }
                }
            }
        }return ans;
    }
};