class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return nums[0];
        return smallk(nums,n-k+1);
    }
    int smallk(vector<int>&a,int k) {				//查找到区间仅含一个元素
        int low=*min_element(a.begin(),a.end());
        int high=*max_element(a.begin(),a.end());
        while(low<high) {               //区间中至少有两个元素时循环
            int mid=low+(high-low)/2;   //保证长度为2时找左中间元素
            int cnt=0;
            for(int i=0;i<a.size();i++) {
                if(a[i]<=mid) cnt++;
            }
            if(cnt>=k)                  //说明mid大了
                high=mid;               //在左区间中继续查找
            else                        //说明mid小了
                low=mid+1;              //在右区间中继续查找
        }
        return low;                     //或者return high
    }
};

