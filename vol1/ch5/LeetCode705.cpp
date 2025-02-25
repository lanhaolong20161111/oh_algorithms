class MyHashSet {
private:
    const static int MAXH=10000;
    const static int P=9997;
    const static int NULLKEY=-1;            //空位置的键
    const static int DELKEY=-2;             //删除位置的键
    int ht[MAXH];                               //哈希表
    int hash(int key) {                         //查找key的哈希地址或者空位置
        int d=key%P;
        while(ht[d]!=key && ht[d]!=NULLKEY) {
            d=(d+1)%MAXH;					//找到重复键/NULLKEY的位置d
        }
        return d;
    }
public:
    MyHashSet() {
        memset(ht,NULLKEY,sizeof(ht));          //初始化哈希表
    }
    
    void add(int key) {                         //插入key
        int d=key%P;                                //求d0
        while(ht[d]!=key && ht[d]!=NULLKEY && ht[d]!=DELKEY) {
            d=(d+1)%MAXH;                       //找到重复键/NULLKEY/DELKEY的位置d
        }
        ht[d]=key;
    }
    
    void remove(int key) {                      //删除key
        int d=hash(key);
        if(ht[d]!=NULLKEY)
            ht[d]=DELKEY; 
    }
    
    bool contains(int key) {                    //是否包含key
        return ht[hash(key)]!=NULLKEY;
    }
};

