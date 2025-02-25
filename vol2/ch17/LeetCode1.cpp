class Solution {
public:
    vector<int> searchRange(vector<int>& nums,int target) {
        int n=nums.size();
        int f=lowerbound(nums,target);
        if(f==n || nums[f]!=target)   //������target��Ԫ�ص����
            return {-1,-1};
        int e=upperbound(nums,target);        //����targetԪ��ʱ
        return {f,e-1};           //���Ϊ[f,e-1]
    }
    int lowerbound(vector<int>&nums,int k) {    //���ҵ�һ�����ڵ���k�����
        int n=nums.size();
        int low=0,high=n;                       //��ʼ��������Ϊ[0,n] 
        while (low<high) {                      //��������������2��Ԫ��ʱѭ��
            int mid=(low+high)/2;
            if (k<=nums[mid])
                high=mid;                       //��������(��mid)�в���
            else
                low=mid+1;                      //���������в���(����mid)
        }
        return low;                             //����low
    }
    int upperbound(vector<int>&nums,int k) {    //���ҵ�һ������k�����
        int n=nums.size();
        int low=0,high=n;                       //��ʼ��������Ϊ[0,n]
        while (low<high) {                      //��������������2��Ԫ��ʱѭ��
            int mid=(low+high)/2;
            if (k<nums[mid])
                high=mid;                   //��������(��mid)�в���
            else
                low=mid+1;                  //k>=nums[mid]���������в���
        }
        return low;                                         //����low
    }
};

