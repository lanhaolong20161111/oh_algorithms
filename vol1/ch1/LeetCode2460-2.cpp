class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int k=0;										//�ۼ�Ϊ0��Ԫ�ظ���
        for (int i=0;i<n;i++) {
            if (nums[i]==0)
                k++;
            else {
                if (i<n-1 && nums[i]==nums[i+1]) {
                    nums[i+1]=0;    //�޸Ĳ���
                    nums[i]*=2;
                }
                nums[i-k]=nums[i];    //����0Ԫ��ǰ��k��λ��
            }
        }
        for(int j=n-k;j<n;j++)        //ĩβ��0
            nums[j]=0;
        return nums;
    }
};

