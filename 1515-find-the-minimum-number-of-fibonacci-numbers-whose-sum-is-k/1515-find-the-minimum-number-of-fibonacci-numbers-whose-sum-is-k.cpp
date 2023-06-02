class Solution {
public:
    int findMinFibonacciNumbers(int A) {
        if(A==1)return 1;
        int x=1,y=1;
        while(x+y<=A){
            int temp=x+y;
            x=y;
            y=temp;
        }if(y==A)return 1;
        return 1+findMinFibonacciNumbers(A-y);
    }
};