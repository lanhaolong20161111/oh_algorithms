template <typename T>
bool cmp(T a,T b) {                         //���ڴ���С����
    return a>b;
}
template <typename T>
class Heap {                                    //�����ݽṹ��ʵ��
    int n;                                  //����Ԫ�ظ���
    vector<T> R;                            //��R[0..n-1]��Ŷ���Ԫ��
    void siftDown(int low,int high) {       //R[low..high]���Զ�����ɸѡ
        int i=low;
        int j=2*i+1;                            //R[j]��R[i]������
        T tmp=R[i];                         //tmp��ʱ��������
        while (j<=high) {                   //ֻ��R[low..high]��Ԫ�ؽ���ɸѡ
            if (j<high && cmp(R[j],R[j+1]))
                j++;                            //���Һ��ӽϴ�,��jָ���Һ���
            if (cmp(tmp,R[j])) {                    //tmp�ĺ��ӽϴ�
                R[i]=R[j];                  //��R[j]������˫��λ����
                i=j; j=2*i+1;                   //�޸�i��jֵ,�Ա��������ɸѡ
            }
            else break;                     //�����ӽ�С����ɸѡ����
        }
        R[i]=tmp;                           //ԭ������������λ��
    }
    void siftUp(int j) {                        //�Ե�����ɸѡ:��Ҷ�ӽ��j����ɸѡ
        int i=(j-1)/2;                          //iָ��R[j]��˫��
        T tmp=R[j];
        while (j!=0) { 
            if (cmp(R[i],tmp)) {                    //�����ӽϴ��򽻻�
                R[j]=R[i];
                j=i; i=(j-1)/2;
            }
            else break;                 //��������ʱ����
        }
        R[j]=tmp;
    }
public:
    Heap():n(0) {}                          //���캯��
    void push(T e) {                                //����Ԫ��e
        R.push_back(e);                     //��e��ӵ�ĩβ
        n++;                                    //����Ԫ�ظ�����1
        if (n==1) return;                           //e��Ϊ���������
        int j=n-1;
        siftUp(j);                              //��Ҷ�ӽ��R[j]����ɸѡ
    }
    T pop() {                               //ɾ���Ѷ�Ԫ��
        T e=R[0];                           //ȡ���Ѷ�Ԫ��
        R[0]=R[n-1];                        //��βԪ�ظ���R[0]
        R.pop_back();
        n--;                                    //Ԫ�ظ�������1
        if(n>1) 
        	siftDown(0,n-1);                        //ɸѡΪһ����
        return e;
    }
    T top() {                               //ȡ�Ѷ�Ԫ��
        return R[0];
    }
    bool empty() {                          //�ж϶��Ƿ�Ϊ��
        return n==0;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        Heap<int> pq;
        for(int x:nums) pq.push(x);
        for(int i=0;i<nums.size();i++) {
            nums[i]=pq.top();
            pq.pop();
        }
        return nums;
    }
};

