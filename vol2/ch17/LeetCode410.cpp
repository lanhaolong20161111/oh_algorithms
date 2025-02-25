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
            if (cnt<m)              //˵��mid����
                high=mid;           //���������м�������
            else                    //˵��midС��
                low=mid+1;          //���������м�������
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

