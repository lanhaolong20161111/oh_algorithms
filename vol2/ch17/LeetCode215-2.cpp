class Solution {
public:
    int findKthLargest(vector<int>& nums,int k) {
        int n=nums.size();
            return quickselect(nums,0,n-1,k);
    }
        int quickselect(vector<int>&a,int s,int t,int k) {
        if (s>=t) return a[s];
            int i=s, j=t;
            int base=a[(i+j)/2];
            while (i<=j) {
                while (i<=j && a[i]>base) {      //从左向右跳过大于base的元素
                    i++;                                            //i指向小于等于base的元素
                }
                while (i<=j && a[j]<base) {      //从右向左跳过小于base的元素
                    j--;                                            //j指向大于等于base的元素
                }
                if (i<=j) {
                    swap(a[i],a[j]);              //a[i]和a[j]交换
                    i++; j--;
                }
            }
            if (s+k-1<=j) {                                 //在左区间查找第k大元素
                return quickselect(a,s,j,k);
            }
            if (s+k-1>=i) {                                 //在右区间查找第k-(i-s)大元素
                return quickselect(a,i,t,k-(i-s));
            }
            return a[j+1];
        }
};

