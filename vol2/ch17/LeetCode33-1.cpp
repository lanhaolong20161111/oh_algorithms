class Solution {
public:
    int search(vector<int>& nums,int target) {        //二分查找算法
        int n=nums.size();
        int base=getBase(nums);             //获取基准位置
        int low=0,high=n-1;
        while (low<=high) {                 //查找区间至少有一个元素时循环
            int mid=(low+high)/2;
            int i=(mid+base)%n;                 //a[mid]=nums[i]
            if (target==nums[i])
                return i;
            if (target>nums[i])
                    low=mid+1;
            else
                    high=mid-1;
        }
        return -1;
}
    int getBase(vector<int>& nums) {                    //查找基准位置
    int low=0,high=nums.size()-1;
        while (low<high) {
            int mid=(low+high)/2;
            if (nums[mid]<nums[high])  high=mid;                       //向左逼近
        else  low=mid+1;                      //在右区间中查找
        }
        return low;
}
};

