class Solution {
public:
    double pow(double x,long long n){
        if(x==1)return 1;
        if(n==0)return 1;
        if(n==1)return x;
        if(n%2){
            return x*pow(x,n-1);
        }else{
            double ret=pow(x,n/2);
            return ret*ret;
        }
    }
    double myPow(double x, int n) {
        long long b=n;
        bool neg=b<0?true:false;
        double ans=pow(x,abs(b));
        if(neg)return 1/ans;
        return ans;
    }
};