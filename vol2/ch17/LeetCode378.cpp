class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {   //���ҵ��������һ��Ԫ��
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<high) {
            int mid=low+(high-low)/2;
            int cnt=Count(matrix,mid);
            if (cnt>=k)              //˵��mid����
                high=mid;              //���������м�������
            else                        //˵��midС��
                low=mid+1;              //���������м�������
        }
        return low;
    }
    int Count(vector<vector<int>>&a,int mid) {
        int n=a.size();
        int i=n-1,j=0;
        int cnt=0;
        while (i>=0 && j<n) {
            if (a[i][j]<=mid) {
                cnt+=i+1;
                j++;
            }
            else i--;
        }
        return cnt;
    }
};

