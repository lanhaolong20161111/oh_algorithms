class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pred(n),postd(n);
        pred[0]=nums[0];                			//求前缀积
        for (int i=1;i<n;i++)
            pred[i]=pred[i-1]*nums[i];
        postd[n-1]=nums[n-1];           			//求后缀积
        for (int i=n-2;i>=0;i--)
            postd[i]=postd[i+1]*nums[i];
        vector<int> ans(n);
        ans[0]=postd[1];
        ans[n-1]=pred[n-2];
        for (int k=1;k<n-1;k++)
            ans[k]=pred[k-1]*postd[k+1];
        return ans;
    }
};

