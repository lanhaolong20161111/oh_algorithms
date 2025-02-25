class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int n=nums.size();
    if (n<2) return false;  //若元素个数小于2，则不能分割
    int s=0;
    int maxe=0;
    for (int e:nums) {        //求所有元素和s和最大元素maxe
      s+=e;
      if(e>maxe) maxe=e;
    }
    if (s%2!=0) return false;   //如果和是奇数，则不能分割
    int W=s/2;          //W为元素和的一半
    if (maxe>W) return false;   //最大元素大于W，则不能分割
      vector<bool> dp(W+1,false);       //dp[r]:是否存在子集和为r
      dp[0]=true;
      for (int i=1;i<=n;i++) { 
        for (int r=W;r>=nums[i-1];r--)  //r从大到小循环（重点）
          dp[r]=dp[r] || dp[r-nums[i-1]];
      }
      return dp[W];
    }
};

