class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n;i++) {
            if (nums[i]!=0) {              //nums[i]Ϊ������Ԫ��
                j++;                         //������Ԫ������
                if (j!=i)                   //���i��j������Ԫ�ؽ���
                    swap(nums[i],nums[j]); 
            }
        }
        for(int i=j+1;i<n;i++)
            nums[i]=0;
    }
};

