class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return nums[0];
        return smallk(nums,n-k+1);
    }
    int smallk(vector<int>&a,int k) {				//���ҵ��������һ��Ԫ��
        int low=*min_element(a.begin(),a.end());
        int high=*max_element(a.begin(),a.end());
        while(low<high) {               //����������������Ԫ��ʱѭ��
            int mid=low+(high-low)/2;   //��֤����Ϊ2ʱ�����м�Ԫ��
            int cnt=0;
            for(int i=0;i<a.size();i++) {
                if(a[i]<=mid) cnt++;
            }
            if(cnt>=k)                  //˵��mid����
                high=mid;               //���������м�������
            else                        //˵��midС��
                low=mid+1;              //���������м�������
        }
        return low;                     //����return high
    }
};

