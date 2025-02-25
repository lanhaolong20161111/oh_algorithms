class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<=2) return n;
        int j=1;            //���ȱ���nums[0]��nums[1]
        for(int i=2;i<n;i++) {
            if (!(nums[j-1]==nums[j] && nums[i]==nums[j])) {      //nums[i]Ϊ������Ԫ��
                j++;                         //������Ԫ������
                if (j!=i)                   //���i��j������Ԫ�ؽ���
                    swap(nums[i],nums[j]); 
            }
        }
        return j+1;
    }
};

