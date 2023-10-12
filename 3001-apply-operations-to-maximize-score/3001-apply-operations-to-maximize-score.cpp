using ll = long long;
class Solution {
public:
    ll binpow(ll a, ll b,ll mod) {
        a %= mod; ll res = 1;
        while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1;}
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        // great problem kuch purane concepts clear krri
        vector<int> prime_factors(n);
        for(int i = 0; i < n; i++){
            int el = nums[i];
            set<int> distinct;
            int root = sqrt(el);
            while (el % 2 == 0){
                if(!distinct.count(2)) distinct.insert(2);
                el =  el / 2;
            }
            for (int j = 3; j <= root; j = j + 2){
                while (el % j == 0){
                    if(!distinct.count(j)) distinct.insert(j);
                    el = el / j;
                }
            }
            if(el >2) if(!distinct.count(el)) distinct.insert(el);
            prime_factors[i] = (int) distinct.size(); // prime score
        }
        
        vector<int> next_greater(n,n);
        stack<int> stc;
        for(int i = 0; i < n; i++){
            while(!stc.empty() and prime_factors[stc.top()] < prime_factors[i] ){
                next_greater[stc.top()] = i; 
                stc.pop();
            }
            stc.push(i);
        }
        
        while(!stc.empty()) stc.pop();
        
        vector<int> prev_greater_equal(n,-1);
        for(int i = n - 1; i >= 0; i--){
            while(!stc.empty() and prime_factors[i] >= prime_factors[stc.top()]){
                prev_greater_equal[stc.top()] = i;
                stc.pop();
            }
            stc.push(i);
        }
        
        vector<pair<int,int>> contribution;
        for(int i = 0; i < n; i++){
            int prev = prev_greater_equal[i];
            int next = next_greater[i];
            
            ll contri = (next - i) * (i - prev); // find the contribution ( in what number of subarrays 
			// will this number be the required x asked in the question )
            if(contri) contribution.push_back({nums[i], contri});
        }
        
        sort(contribution.begin(), contribution.end(), [&](auto a, auto b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        });
        
        ll ans = 1, mod = 1e9 + 7;
        for(auto el : contribution){
            if(k == 0) break;
            int mn = min(k, el.second);
            ans *= binpow(el.first, mn, mod);
            ans %= mod;
            k -= mn;
        }
        return ans;
        
    }
};