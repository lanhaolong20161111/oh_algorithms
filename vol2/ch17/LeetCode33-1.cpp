class Solution {
public:
    int search(vector<int>& nums,int target) {        //���ֲ����㷨
        int n=nums.size();
        int base=getBase(nums);             //��ȡ��׼λ��
        int low=0,high=n-1;
        while (low<=high) {                 //��������������һ��Ԫ��ʱѭ��
            int mid=(low+high)/2;
            int i=(mid+base)%n;                 //a[mid]=nums[i]
            if (target==nums[i])
                return i;
            if (target>nums[i])
                    low=mid+1;
            else
                    high=mid-1;
        }
        return -1;
}
    int getBase(vector<int>& nums) {                    //���һ�׼λ��
    int low=0,high=nums.size()-1;
        while (low<high) {
            int mid=(low+high)/2;
            if (nums[mid]<nums[high])  high=mid;                       //����ƽ�
        else  low=mid+1;                      //���������в���
        }
        return low;
}
};

