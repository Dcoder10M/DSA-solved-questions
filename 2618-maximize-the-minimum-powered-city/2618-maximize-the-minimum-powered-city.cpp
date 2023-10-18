class Solution {
public:
    typedef long long ll;
    bool solve(ll mid,vector<int>& stations,ll r,ll k){
        ll n=stations.size();
        vector<ll> power(n+1,0);
        for(ll i=0;i<n;i++){
            ll left=max(0ll,i-r);
            ll right=min(n,i+r+1);
            power[left]+=stations[i];
            power[right]-=stations[i];
        }
        for(int i=1;i<n;i++)power[i]+=power[i-1];
        vector<ll> past(n+1,0);
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(i!=0)past[i]+=past[i-1];
            if(power[i]+past[i]<mid){
                ll req=mid-(power[i]+past[i]);
                past[i]+=req;
                ans+=req;
                ll right=min(n,i+r+r+1);
                past[right]-=req;
            }
        }return ans<=k;
    }
    long long maxPower(vector<int>& stations, ll r, ll k) {
        ll low=0,high=1e12;
        while(low+1<high){
            ll mid=(low+high)/2;
            if(solve(mid,stations,r,k)){
                low=mid;
            }else high=mid;
        }return low;
    }
};