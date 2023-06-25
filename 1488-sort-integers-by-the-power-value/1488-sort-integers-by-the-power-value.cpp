class Solution {
public:
    int calcPower(int n){
        int power = 0 ;
        while(n != 1){
            if(n % 2 == 0){
                n = n / 2 ;
                power++ ;
            }
            else{
                n = 3 * n + 1 ;
                power++ ;
            }
        }
        return power ;
    }

    int getKth(int lo, int hi, int k) {

        vector<vector<int>> powerVec ;
        
        for(int i=lo; i<=hi; i++){
            int p = calcPower(i) ;
            vector<int> v = {p, i} ;
            powerVec.push_back(v) ;
        }

        sort(powerVec.begin(), powerVec.end()) ;

        return powerVec[k-1][1] ;
    }
};