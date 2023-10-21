class Solution {
public:
    int solve(int ind,vector<int> &temp,int mask,vector<string> &arr){
        if(ind==temp.size())return 0;
        int ans=0;
        if((mask&temp[ind])==0){
            ans=arr[ind].size()+solve(ind+1,temp,mask|(temp[ind]),arr);
        }
        ans=max(ans,solve(ind+1,temp,mask,arr));
        return ans;
    }
    int maxLength(vector<string>& arr) {
        vector<int> temp;
        vector<string> arrr;
        for(auto i:arr){
            int help=0;
            for(auto j:i){
                if((help&(1<<(j-'a')))!=0){
                    help=0;
                    cout<<i<<endl;
                    break;
                }
                help=help|(1<<(j-'a'));
            }
            if(help!=0){
            temp.push_back(help);arrr.push_back(i);}
        }
        for(auto i:temp)cout<<i<<" ";
        return solve(0,temp,0,arrr);
    }
};