typedef long long ll;

class Solution {
public:
    int integerBreak(int n) {
        ll ans=0;
        for(ll i=2;i<=n;i++){
            ll common=n/i;
            // cout<<common<<endl;
            ll rem=n-(i*common);
            // cout<<rem<<endl;
            ll oneplus=common+1;
            // cout<<oneplus<<endl;
            ll compare=1ll*pow(oneplus,rem)*pow(common,i-rem);
            ans=max(ans,compare);
        }return ans;
    }
};