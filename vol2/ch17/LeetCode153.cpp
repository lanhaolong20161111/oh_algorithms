class Solution {
public:
    int findMin(vector<int>& nums) {					//查找到区间仅含一个元素
        int low=0,high=nums.size()-1;
        while(low<high) {
            int mid=(low+high)/2;
            if (nums[mid]<nums[high]) high=mid;  //向左区间逼近
            else low=mid+1;             //在右区间中查找
        }
        return nums[low];
    }
};

