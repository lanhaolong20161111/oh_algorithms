class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int n=nums.size();
    if (n<2) return false;  //��Ԫ�ظ���С��2�����ָܷ�
    int s=0;
    int maxe=0;
    for (int e:nums) {        //������Ԫ�غ�s�����Ԫ��maxe
      s+=e;
      if(e>maxe) maxe=e;
    }
    if (s%2!=0) return false;   //����������������ָܷ�
    int W=s/2;          //WΪԪ�غ͵�һ��
    if (maxe>W) return false;   //���Ԫ�ش���W�����ָܷ�
      vector<bool> dp(W+1,false);       //dp[r]:�Ƿ�����Ӽ���Ϊr
      dp[0]=true;
      for (int i=1;i<=n;i++) { 
        for (int r=W;r>=nums[i-1];r--)  //r�Ӵ�Сѭ�����ص㣩
          dp[r]=dp[r] || dp[r-nums[i-1]];
      }
      return dp[W];
    }
};

