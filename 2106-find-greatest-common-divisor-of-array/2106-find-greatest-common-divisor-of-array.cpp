class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a; 
        if(b>a)return gcd(b,a);
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int ans=0;
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        ans=gcd(mx,mn);
        return ans;
    }
};