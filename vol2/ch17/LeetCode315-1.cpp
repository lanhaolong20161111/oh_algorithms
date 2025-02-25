struct IDX {
    int val;                                        //����
    int idx;                                        //������nums�е��±�
    IDX() {}                                        //���캯��
    IDX(int v,int i):val(v),idx(i) {}               //���ع��캯�� 
};
class Solution {
    vector<int> counts;                         //��Ž��������
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<IDX> a;                              //a���ÿ��Ԫ�ؼ�������
        for (int i=0;i<n;i++) {
            a.push_back(IDX(nums[i],i));            //a����ÿ��Ԫ���м����±� 
            counts.push_back(0);                    //��ʼ��counts����Ԫ��Ϊ0 
        }
        mergesort(a,0,n-1);
        return counts;
    }
    void mergesort(vector<IDX>&a,int low,int high) {   //��·�鲢����
        if (low<high) {
            int mid=(low+high)/2;
            mergesort(a,low,mid);
            mergesort(a,mid+1,high);
            merge(a,low,mid,high);
        }
    }
    void merge(vector<IDX>&a,int low,int mid,int high) {        //��·�鲢
        int i=low,j=mid+1;                         //��·�鲢
        vector<IDX> tmp;                           //������ʱ�鲢�ռ�tmp
        while (i<=mid && j<=high) {
            if (a[i].val<=a[j].val) {         //a[i]Ԫ�ؽ�С
                tmp.push_back(a[i]);           //�鲢a[i]
                counts[a[i].idx]+=j-mid-1;     //�ۼ�a[i]λ��ǰ�Ƶ�Ԫ�ظ���
                i++;
            }
            else {                                  //a[j]Ԫ�ؽ�С
                tmp.push_back(a[j]);                     //�鲢a[j]
                j++;
            }
        }
        while (i<=mid) {                                        //��1����û�б�����
            tmp.push_back(a[i]);
            counts[a[i].idx]+=high-mid;
            i++;
        }
        while (j<=high) {                                       //��2����û�б�����
            tmp.push_back(a[j]);
            j++;
        }
        for (int j=0,i=low;i<=high;j++,i++)          //��tmp���ƻ�a��
            a[i]=tmp[j];
    }
};

