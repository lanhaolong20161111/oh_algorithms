class CustomStack {
    int *data;                                          //���ջԪ�صĶ�̬����
    int capacity;                                       //data���������
    int top;                                            //ջ��ָ��
public:
    CustomStack(int maxSize) {      //���캯��
        data=new int[maxSize];
        capacity=maxSize;
        top=-1;
    }
    void push(int x) {              //��ջx
        if(top+1<capacity) {        //û�г��������ʱ
            top++;
            data[top]=x;
        }
    }
   
    int pop() {                  //��ջ
        if(top==-1)
            return -1;
        else {
            int e=data[top];
            top--;
            return e;
        }
    }
    
    void increment(int k,int val) {     //��������
        int m=(top+1<=k?top+1:k);
        for (int i=0;i<m;i++)
            data[i]+=val;
    }
};

