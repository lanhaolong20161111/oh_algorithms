class Solution {
public:
    int search(vector<int>& nums,int target) {        //二分查找算法
        int low=0,high=nums.size()-1;
        while(low<=high) {                      //查找区间至少有一个元素时循环
            int mid=(low+high)/2;
            if (nums[mid]==target)              //找到后直接返回mid
                return mid;
            if (nums[mid]<nums[high]) {         //nums[mid]属于右有序段
                if (nums[mid]<=target && target<=nums[high])
                        low=mid+1;                  //右有序段后面部分(有序)中查找
                else
                high=mid-1;                 //在nums[low..mid-1]中查找
            }
            else {                                  //nums[mid]属于左有序段
                if (nums[low]<=target && target<=nums[mid])
                        high=mid-1;                 //在左有序段前面部分(有序)中查找
                else
                        low=mid+1;                  //在nums[mid+1..high]中查找
            }
        }
        return -1;
    }
};

