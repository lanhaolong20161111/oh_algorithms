class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for (int i=0;i<n;i++) {
            if (nums[i]==0) k++;            //nums[i]为要删除的元素
            else nums[i-k]=nums[i];         //nums[i]为要保留的元素
        }
        for(int i=n-k;i<n;i++)
            nums[i]=0;
  }
};

