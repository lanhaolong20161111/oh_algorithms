class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0) {
            if(nums1[i]>nums2[j]) {          //�鲢�ϴ��nums1[i]
                nums1[k]=nums1[i];
                i--; k--;
            }
            else {                                      //�鲢�ϴ��nums2[j]
                nums1[k]=nums2[j];
                j--; k--;
            }
        }
        while(i>=0) {                               //nums1û�й鲢��ʱ
            nums1[k]=nums1[i];
            i--; k--;
        }
        while(j>=0) {                               //nums2û�й鲢��ʱ
            nums1[k]=nums2[j];
            j--; k--;
        }
    }
};

