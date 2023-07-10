class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(auto i:bills){
            if(i==5)five++;
            if(i==10){
                five--;
                ten++;
            }
            if(five<0)return false;
            if(i==20){
                if(ten && five){
                    ten--;
                    five--;
                }else if(five>=3){
                    five-=3;
                }else return false;
            }
            if(five<0)return false;
        }return true;
    }
};