class Solution {
public:
    vector<int> searchRange(vector<int>& nums,int target) {
        int n=nums.size();
        int f=lowerbound(nums,target);
        if(f==n || nums[f]!=target)   //不存在target的元素的情况
            return {-1,-1};
        int e=upperbound(nums,target);        //存在target元素时
        return {f,e-1};           //结果为[f,e-1]
    }
    int lowerbound(vector<int>&nums,int k) {    //查找第一个大于等于k的序号
        int n=nums.size();
        int low=0,high=n;                       //初始查找区间为[0,n] 
        while (low<high) {                      //查找区间至少有2个元素时循环
            int mid=(low+high)/2;
            if (k<=nums[mid])
                high=mid;                       //在左区间(含mid)中查找
            else
                low=mid+1;                      //在右区间中查找(不含mid)
        }
        return low;                             //返回low
    }
    int upperbound(vector<int>&nums,int k) {    //查找第一个大于k的序号
        int n=nums.size();
        int low=0,high=n;                       //初始查找区间为[0,n]
        while (low<high) {                      //查找区间至少有2个元素时循环
            int mid=(low+high)/2;
            if (k<nums[mid])
                high=mid;                   //在左区间(含mid)中查找
            else
                low=mid+1;                  //k>=nums[mid]在右区间中查找
        }
        return low;                                         //返回low
    }
};

