class CustomStack {
    int *data;                                          //存放栈元素的动态数组
    int capacity;                                       //data数组的容量
    int top;                                            //栈顶指针
public:
    CustomStack(int maxSize) {      //构造函数
        data=new int[maxSize];
        capacity=maxSize;
        top=-1;
    }
    void push(int x) {              //进栈x
        if(top+1<capacity) {        //没有出现上溢出时
            top++;
            data[top]=x;
        }
    }
   
    int pop() {                  //出栈
        if(top==-1)
            return -1;
        else {
            int e=data[top];
            top--;
            return e;
        }
    }
    
    void increment(int k,int val) {     //增量操作
        int m=(top+1<=k?top+1:k);
        for (int i=0;i<m;i++)
            data[i]+=val;
    }
};

