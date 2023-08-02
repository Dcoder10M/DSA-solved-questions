class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        //cpy->current length of copied A's
        int cpy=1;
        //num->current length of A's on notepad
        int num=1;
        //ans->stores answer
        int ans=1;
        //till number of notepad is not n
        while(num!=n){
            ////if n is divisible by copied len then paste
            if(n%cpy==0){
                num+=cpy;
                ans++;
            }
            //if new number on notepad divides the target n then copy the new number 
            if(num!=n && n%num==0){
                ans++;
                cpy=num;
            }
        }
        return ans;
    }
};