class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return maxsub(nums,0,n-1); 
    }
    int maxsub(vector<int>&a,int low,int high) {    //分治算法
        if (low==high)                              //子数组只有一个元素时
            return a[low];
        int mid=(low+high)/2;                   //求中间位置
        int leftsum=maxsub(a,low,mid);          //求左边子数组之和
        int rightsum=maxsub(a,mid+1,high);      //求右边子数组之和
        int leftbordersum=0,maxleftbordersum=a[mid];
        for (int i=mid;i>=low;i--) {                    //求左段a[i..mid]的最大子数组和
            leftbordersum+=a[i];
            maxleftbordersum=max(maxleftbordersum,leftbordersum);
        }
        int rightbordersum=0,maxrightbordersum=a[mid+1];
        for (int j=mid+1;j<=high;j++) {             //求右段a[mid+1..j]的最大子数组和
            rightbordersum+=a[j];
            maxrightbordersum=max(maxrightbordersum,rightbordersum);
        }
        int ans=max(max(leftsum,rightsum),maxleftbordersum+maxrightbordersum);
        return ans;
    }
};

