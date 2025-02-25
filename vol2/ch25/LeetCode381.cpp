class RandomizedCollection {
private:   
    vector<int> nums;                               //存放全部元素
    unordered_map<int,unordered_set<int>> hmap;     //存放元素在nums中的索引
public:
        RandomizedCollection() {}                          //初始化

        bool insert(int val) {                               //插入val
            hmap[val].insert(nums.size());                  //val插入到nums末尾
            nums.push_back(val);
            if(hmap[val].size()==1)
                return true;                                    //val值的个数为1，返回true
            else
                return false;                                   //val值的个数大于1，返回false
        }

        bool remove(int val) {                                //删除val
            if(hmap[val].empty())                              //没有找到val返回false
                return false;
            auto it=hmap[val].begin();                   //在hmap[val]找第一个val的位置
            int i=*it;                                     //第一个val的索引
            hmap[val].erase(it);                           //从hmap[val]中删除该val
            if(hmap[val].empty()) hmap.erase(val);      //hmap[val]为空删除该元素
            if(i!=nums.size()-1) {                  //删除的不是nums的末尾元素时
                int lastk=nums[nums.size()-1];              //求末尾关键字lastk
                nums[i]=lastk;                             //将元素lastk移到索引i处
                hmap[lastk].erase(nums.size()-1);           //hmap[lastk]中删除n-1
                hmap[lastk].insert(i);
            }
            nums.pop_back();                                    //从nums中删除末尾元素
            return true;
        }

        int getRandom() {                                 //随机返回元素
           int j=rand()% nums.size(); // 0~n
            return nums[j];
        }
};

