class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int k=0;										//累计为0的元素个数
        for (int i=0;i<n;i++) {
            if (nums[i]==0)
                k++;
            else {
                if (i<n-1 && nums[i]==nums[i+1]) {
                    nums[i+1]=0;    //修改操作
                    nums[i]*=2;
                }
                nums[i-k]=nums[i];    //将非0元素前移k个位置
            }
        }
        for(int j=n-k;j<n;j++)        //末尾补0
            nums[j]=0;
        return nums;
    }
};

