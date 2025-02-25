class RandomizedSet:
    def __init__(self):
        self.nums=[]                  #存放全部元素
        self.hmap={}               #<整数,索引>哈希表

    def insert(self, val: int) -> bool:
        if val not in self.hmap:     #元素不存在时插入
            self.nums.append(val)               #在nums末尾插入val
            self.hmap[val]=len(self.nums)-1       #val的索引为n-1
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.hmap:          #找到key
            i=self.hmap[val]                          #找到val的索引i
            lastk=self.nums[len(self.nums)-1]              #求末尾关键字lastk
            self.nums[i]=lastk                      #将末尾关键字移到i索引处
            self.hmap[lastk]=i					#重置hmap[lastk]
            del self.hmap[val]                     #删除val关键字
            self.nums.pop()                    #将nums末尾元素删除
            return True
        return False

    def getRandom(self) -> int:
        j=random.randrange(0,len(self.nums),1)             #返回0~n-1的随机数
        return self.nums[j]
