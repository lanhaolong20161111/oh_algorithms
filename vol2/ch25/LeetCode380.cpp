class RandomizedSet{
   vector<int> nums;                   					//存放全部元素
        unordered_map<int,int> hmap;               //<整数,索引>哈希映射
    public:
    RandomizedSet() { }
        bool insert(int val) {                              //插入val
        if(hmap.find(val)==hmap.end()) {          //元素不存在时插入
            nums.push_back(val);                //在nums末尾插入val
            hmap[val]=nums.size()-1;            //val的索引为n-1
            return true;
        }
        return false;
    }
    bool remove(int val) {                              //删除val
        if(hmap.find(val)!=hmap.end()) {          //找到key
            int i=hmap[val];                           //找到val的索引i
            int lastk=nums[nums.size()-1];              //求末尾关键字lastk
            nums[i]=lastk;                          //将末尾关键字移到i索引处
            hmap[lastk]=i;						//重置hmap[lastk]
            hmap.erase(val);                           //删除val关键字
            nums.pop_back();                //将nums末尾元素删除
            return true;
        }
        return false;
    }
    int getRandom() {                       //随机返回一个key
        int j=rand()%nums.size();                //返回0~n-1的随机数
        return nums[j];
    }
};

