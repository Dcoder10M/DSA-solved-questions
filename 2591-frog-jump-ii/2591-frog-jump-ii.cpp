#include <bits/stdc++.h>
class Solution {
public:
   bool isPossible(int mid, vector<int> v)
    {
        int n = v.size();
        int current_pos = v[0];
        for(int i=1; i<n; i++)
        {
            if(v[i]-current_pos > mid)
            {
                current_pos = v[i-1];
                v[i-1] = -1;
            }
            if(i==n && current_pos != n-1)
            {
                if(v[n-1] - current_pos <= mid)
                {
                    current_pos = v[n-1];
                }
                else
                {
                    return false;
                }
            }
        }
        current_pos = v[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(current_pos-v[i] <= mid && v[i] != -1)
            {
                current_pos = v[i];
            }
        }
        if(current_pos == v[0])
        {
            return true;
        }

        return false;
    }
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int high=stones[n-1]-stones[0]+1;
        int low=0;
        while(low+1<high){
            int mid=(low+high)/2;
            if(isPossible(mid,stones)){
                high=mid;
            }else low=mid;
        }return high;
    }
};