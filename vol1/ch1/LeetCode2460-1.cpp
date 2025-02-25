class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for (int i=0;i<n;i++) {
            if (nums[i]==0)       //跳过0元素
                continue;
            else {
                if (i<n-1 && nums[i]==nums[i+1]) {
                    nums[i+1]=0;    //修改操作
                    nums[i]*=2;
                }
                nums[k]=nums[i];    //将非0元素插入到nums[k]处
                k++;
            }
        }
        for(int j=k;j<n;j++)        //末尾补0
            nums[j]=0;
        return nums;
    }
};

