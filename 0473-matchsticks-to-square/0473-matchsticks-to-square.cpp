class Solution {
public:
    bool solve(vector<int> &a,int ind,vector<int> &side){
        if(ind==a.size()){
            return side[0]==side[1] && side[1]==side[2] && side[2]==side[3];
        }
        for(int i=0;i<4;i++){
            if(side[i]<a[ind])continue;
            int j=i-1;
            bool ans=false;
            while(j>=0){
                if(side[i]==side[j]){
                    ans=true;
                    break;
                }
                j--;
            }
            if(ans)continue;
            side[i]-=a[ind];
            if(solve(a,ind+1,side))return true;
            side[i]+=a[ind];
        }return false;
    }
    bool makesquare(vector<int>& a) {
        int sum=0;
        for(auto i:a)sum+=i;
        if(sum%4!=0)return false;
        int peri=sum/4;
        sort(a.rbegin(),a.rend());
        vector<int> side={peri,peri,peri,peri};
        return solve(a,0,side);
    }
};