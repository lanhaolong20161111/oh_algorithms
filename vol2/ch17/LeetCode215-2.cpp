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
                while (i<=j && a[i]>base) {      //����������������base��Ԫ��
                    i++;                                            //iָ��С�ڵ���base��Ԫ��
                }
                while (i<=j && a[j]<base) {      //������������С��base��Ԫ��
                    j--;                                            //jָ����ڵ���base��Ԫ��
                }
                if (i<=j) {
                    swap(a[i],a[j]);              //a[i]��a[j]����
                    i++; j--;
                }
            }
            if (s+k-1<=j) {                                 //����������ҵ�k��Ԫ��
                return quickselect(a,s,j,k);
            }
            if (s+k-1>=i) {                                 //����������ҵ�k-(i-s)��Ԫ��
                return quickselect(a,i,t,k-(i-s));
            }
            return a[j+1];
        }
};

