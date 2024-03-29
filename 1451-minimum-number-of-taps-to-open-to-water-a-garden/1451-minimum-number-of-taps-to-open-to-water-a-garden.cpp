class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min=0,max=0,open=0,index=0;
        while(max<n){
            for(int i=index;i<n+1;i++){
                if(i-ranges[i]<=min && i+ranges[i]>max){
                    max=i+ranges[i];
                    index=i;
                }
            }
            if(min==max)return -1;
            open++;
            min=max;
        }return open;
    }
};