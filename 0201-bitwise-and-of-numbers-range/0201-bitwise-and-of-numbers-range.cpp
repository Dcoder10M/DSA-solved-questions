class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left!=0 && right!=0 && left!=right){
            count++;
            left=left>>1;
            right=right>>1;
        }if(left==0)return 0;
        return left<<count;
    }
};