class Solution {
public:
    int splitArray(vector<int>& nums,int m) {
        int n=nums.size();
        int low=0,high=0;
        for(int e:nums) {
            low=max(low,e);
            high+=e;
        }
        while (low<high) {
            int mid=(low+high)/2;
            int cnt=Count(nums,mid);
            if (cnt<m)              //说明mid大了
                high=mid;           //在左区间中继续查找
            else                    //说明mid小了
                low=mid+1;          //在右区间中继续查找
        }
        return  low;
    }
    int Count(vector<int>& nums, int mid) {
        int cursum=0,cnt=0;
        for (int i=0;i<nums.size();i++) {
            cursum+=nums[i];
            if (cursum>mid) {
                cursum=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};

