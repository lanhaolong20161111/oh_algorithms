class Solution {
public:
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(),1);        //numsǰ��β����1����Ӱ����
    nums.push_back(1);
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int length=3;length<=n;length++) {
      for(int i=0;i<n-length+1;i++) {
        int j=i+length-1;         //����[i,j]�ĳ���Ϊlength
        for(int m=i+1;m<j;m++)    //�ָ��Ϊm
          dp[i][j]=max(dp[i][j],dp[i][m]+dp[m][j]+nums[i]*nums[m]*nums[j]);
      }
    }
    return dp[0][n-1];
  }
};

