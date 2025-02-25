class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return maxsub(nums,0,n-1); 
    }
    int maxsub(vector<int>&a,int low,int high) {    //�����㷨
        if (low==high)                              //������ֻ��һ��Ԫ��ʱ
            return a[low];
        int mid=(low+high)/2;                   //���м�λ��
        int leftsum=maxsub(a,low,mid);          //�����������֮��
        int rightsum=maxsub(a,mid+1,high);      //���ұ�������֮��
        int leftbordersum=0,maxleftbordersum=a[mid];
        for (int i=mid;i>=low;i--) {                    //�����a[i..mid]������������
            leftbordersum+=a[i];
            maxleftbordersum=max(maxleftbordersum,leftbordersum);
        }
        int rightbordersum=0,maxrightbordersum=a[mid+1];
        for (int j=mid+1;j<=high;j++) {             //���Ҷ�a[mid+1..j]������������
            rightbordersum+=a[j];
            maxrightbordersum=max(maxrightbordersum,rightbordersum);
        }
        int ans=max(max(leftsum,rightsum),maxleftbordersum+maxrightbordersum);
        return ans;
    }
};

