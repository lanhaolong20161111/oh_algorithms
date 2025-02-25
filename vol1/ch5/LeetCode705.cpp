class MyHashSet {
private:
    const static int MAXH=10000;
    const static int P=9997;
    const static int NULLKEY=-1;            //��λ�õļ�
    const static int DELKEY=-2;             //ɾ��λ�õļ�
    int ht[MAXH];                               //��ϣ��
    int hash(int key) {                         //����key�Ĺ�ϣ��ַ���߿�λ��
        int d=key%P;
        while(ht[d]!=key && ht[d]!=NULLKEY) {
            d=(d+1)%MAXH;					//�ҵ��ظ���/NULLKEY��λ��d
        }
        return d;
    }
public:
    MyHashSet() {
        memset(ht,NULLKEY,sizeof(ht));          //��ʼ����ϣ��
    }
    
    void add(int key) {                         //����key
        int d=key%P;                                //��d0
        while(ht[d]!=key && ht[d]!=NULLKEY && ht[d]!=DELKEY) {
            d=(d+1)%MAXH;                       //�ҵ��ظ���/NULLKEY/DELKEY��λ��d
        }
        ht[d]=key;
    }
    
    void remove(int key) {                      //ɾ��key
        int d=hash(key);
        if(ht[d]!=NULLKEY)
            ht[d]=DELKEY; 
    }
    
    bool contains(int key) {                    //�Ƿ����key
        return ht[hash(key)]!=NULLKEY;
    }
};

