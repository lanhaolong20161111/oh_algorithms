class PhoneDirectory {
    unordered_set<int> hset;       //用于判重
    queue<int> qu;                      //用户队列
public:
    PhoneDirectory(int maxNumbers) {    //初始化
        for(int i=0;i<maxNumbers;i++)
            qu.push(i);
    }
    
    int get() {                         //分配
        if(!qu.empty()){
            int x=qu.front(); qu.pop();
            hset.insert(x);
            return x;
        }
        else return -1;
    }
    
    bool check(int number) {            //检查
        if(hset.count(number)==1)
            return false;
        else
            return true;
    }
    
    void release(int number) {          //释放
        if(hset.count(number)==1) {
            hset.erase(number);
            qu.push(number);
        }
    }
};

