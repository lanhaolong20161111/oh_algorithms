class Solution {
public:
    int findKthLargest(vector<int>& nums,int k) {
        int n=nums.size();
        return quickselect(nums,0,n-1,k);
    }
    int quickselect(vector<int>&a,int s,int t,int k) {  //��a[s..t]�������ҵ�k���Ԫ��
        if (s<t) {                  //���������ٴ���2��Ԫ�ص����
            int i=partition1(a,s,t);
            if (k-1==i)
                return a[i];
            else if (k-1<i)
                return quickselect(a,s,i-1,k);  //���������еݹ����
            else
                return quickselect(a,i+1,t,k);          //���������еݹ����
        }
        else return a[k-1];
    }
    int partition1(vector<int>&a,int s,int t) {          //�����㷨1�����ڵݼ�����
	    int i=s,j=t;
    int base=a[s];                      //��������Ԫ����Ϊ��׼
    while(i<j) {                       //�����˽������м����,ֱ��i=jΪֹ
        while (i<j && a[j]<=base) 
            j--;                        //���������Ҵ���base��a[j]
        if(i<j) {
            a[i]=a[j];                  //��a[j]ǰ�Ƶ�a[i]��λ��
            i++;
        }
        while (i<j && a[i]>=base) 
            i++;                        //����������С��base��a[i]
        if(i<j) {
            a[j]=a[i];                  //��a[i]���Ƶ�a[j]��λ��
            j--;
        }
    }
    a[i]=base;
    return i;
}
};

