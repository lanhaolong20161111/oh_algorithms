class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for (int i=0;i<n;i++) {
            if (nums[i]==0)       //����0Ԫ��
                continue;
            else {
                if (i<n-1 && nums[i]==nums[i+1]) {
                    nums[i+1]=0;    //�޸Ĳ���
                    nums[i]*=2;
                }
                nums[k]=nums[i];    //����0Ԫ�ز��뵽nums[k]��
                k++;
            }
        }
        for(int j=k;j<n;j++)        //ĩβ��0
            nums[j]=0;
        return nums;
    }
};

