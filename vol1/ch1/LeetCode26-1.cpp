class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;										//���ȱ���nums[0]
        for(int i=1;i<nums.size();i++) {
            if (nums[i]!=nums[i-1]) {           //��������Ԫ�����²���
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

