class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]!=val) {     					//将保留的元素重新插入
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

