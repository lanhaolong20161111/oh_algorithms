class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {   //查找到区间仅含一个元素
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<high) {
            int mid=low+(high-low)/2;
            int cnt=Count(matrix,mid);
            if (cnt>=k)              //说明mid大了
                high=mid;              //在左区间中继续查找
            else                        //说明mid小了
                low=mid+1;              //在右区间中继续查找
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

