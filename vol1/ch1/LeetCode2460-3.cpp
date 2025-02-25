class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for (int i=0;i<n;i++) {
            if (nums[i]==0)       //跳过0元素
                continue;
            else {
                if (i<n-1 && nums[i]==nums[i+1]) {
                    nums[i+1]=0;    //修改操作
                    nums[i]*=2;
                }
                j++;                   //将非0元素nums[i]移到保留区间
                if(j!=i)
                    swap(nums[i],nums[j]); 
            }
        }
        for(int i=j+1;i<n;i++)        //末尾补0
            nums[i]=0;
        return nums;
    }
};

