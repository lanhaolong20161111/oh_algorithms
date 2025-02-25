class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=nums[0];                //求前缀积
        for (int i=1;i<n;i++)
            ans[i]=ans[i-1]*nums[i];
        ans[n-1]=ans[n-2];
        int postd=nums[n-1];    //求后缀积
        for (int k=n-2;k>=1;k--) {
            ans[k]=ans[k-1]*postd;
            postd*=nums[k];
        }
        ans[0]=postd;
        return ans;
    }
};

