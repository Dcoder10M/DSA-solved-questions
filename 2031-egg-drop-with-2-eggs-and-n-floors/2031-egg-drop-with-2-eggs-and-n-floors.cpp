class Solution {
public:
    int twoEggDrop(int n) {
        int ans=1;
        int temp=1;
        while(temp<n){
            ans++;
            temp=(ans*(ans+1))/2;
        }
        return ans;
    }
};