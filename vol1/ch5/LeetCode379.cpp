class PhoneDirectory {
    unordered_set<int> hset;       //��������
    queue<int> qu;                      //�û�����
public:
    PhoneDirectory(int maxNumbers) {    //��ʼ��
        for(int i=0;i<maxNumbers;i++)
            qu.push(i);
    }
    
    int get() {                         //����
        if(!qu.empty()){
            int x=qu.front(); qu.pop();
            hset.insert(x);
            return x;
        }
        else return -1;
    }
    
    bool check(int number) {            //���
        if(hset.count(number)==1)
            return false;
        else
            return true;
    }
    
    void release(int number) {          //�ͷ�
        if(hset.count(number)==1) {
            hset.erase(number);
            qu.push(number);
        }
    }
};

