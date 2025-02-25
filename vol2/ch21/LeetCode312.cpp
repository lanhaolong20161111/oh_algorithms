class Solution {
public:
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(),1);        //nums前后尾插入1，不影响结果
    nums.push_back(1);
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int length=3;length<=n;length++) {
      for(int i=0;i<n-length+1;i++) {
        int j=i+length-1;         //区间[i,j]的长度为length
        for(int m=i+1;m<j;m++)    //分割点为m
          dp[i][j]=max(dp[i][j],dp[i][m]+dp[m][j]+nums[i]*nums[m]*nums[j]);
      }
    }
    return dp[0][n-1];
  }
};

