class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
    vector<int> partition2(vector<int>&a,int s,int t) { //�����㷨2�����ڵ�������
    int base=a[(s+t)/2];
    int i=s,j=t;
    while(i<=j) {
        while (i<=j && a[i]<base) i++;      //������������С��base��Ԫ��
        while (i<=j && a[j]>base) j--;      //����������������base��Ԫ��
        if(i<=j) {
            swap(a[i],a[j]);                    //a[i]��a[j]����
            i++;j--;
        }
    }
    return {j,i};
    }
    void quicksort(vector<int>&a,int s,int t) { //��������
        if(s<t) {
            vector<int> p=partition2(a,s,t); 
            quicksort(a,s,p[0]);
            quicksort(a,p[1],t);
        }
    }
};

