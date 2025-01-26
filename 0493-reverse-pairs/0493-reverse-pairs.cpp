class Solution {
private:
    void merg3e(vector<int> &nums, int low, int mid ,int high, int &count)
    {
        int j = mid + 1;
        for(int i = low; i<=mid ; i++)
        {
            while(j<=high && nums[i] > 2*(long long)nums[j])
            {
                j++;
            }
            count += j - (mid+1);
        }
        int size = high - low + 1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left <= mid && right <= high)
        {
            if(nums[left] < nums[right])
            {
                temp[k++] = nums[left++];
            }
            else
            {
                temp[k++] = nums[right++];
            }
        }

        while(left <= mid)
        {
            temp[k++] = nums[left++];
        }
        while(right <= high)
        {
            temp[k++] = nums[right++];
        }
        int m = 0;
        for(int i = low; i<= high; i++)
        {
            nums[i] = temp[m++];
        }
    } 


    void merge(vector<int> &nums,int l,int mid,int r,int &count){
        int i=l,j=mid+1;
        int jj=mid+1;
        for(int k = l; k<=mid ; k++)
        {
            while(jj<=r && nums[k]*1ll > (long long)2*nums[jj]*1ll)
            {
                jj++;
            }
            count += jj - (mid+1);
        }
        vector<int> temp;
   
        while(i<=mid && j<=r){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid){
                temp.push_back(nums[i]);
    i++;
        }
        
        while(j<=r){

                temp.push_back(nums[j]);
                j++;
            
        }
        int curr=0;
        for(int k=l;k<=r;k++){
            nums[k]=temp[curr++];
        }
    }

    void mergeSort(vector<int> &nums,int l,int r, int &count){
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        mergeSort(nums,l,mid,count);
        mergeSort(nums,mid+1,r,count);
        merge(nums,l,mid,r,count);
    }
public :
    int reversePairs(vector<int>& nums) {
        int count = 0;
        // mergesort(nums,0,nums.size()-1, count);
        mergeSort(nums,0,nums.size()-1,count);
        return count;
    }
};