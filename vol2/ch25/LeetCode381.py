class RandomizedCollection:
    def __init__(self):
        self.nums=[]                     #存放全部元素
        self.hmap={}                     #存放元素在nums中的索引

    def insert(self, val: int)-> bool:
        self.nums.append(val)
        if val not in self.hmap:
            hset=set()
            hset.add(len(self.nums)-1)
            self.hmap[val]=hset
            return True
        else:
            hset=self.hmap.get(val)
            hset.add(len(self.nums)-1)
            self.hmap[val]=hset
            return False

    def remove(self, val: int)->bool:
        if val not in self.hmap:                             #没有找到val返回false
            return False
        i=self.hmap[val].pop()                #从hset删除元素i并返回之
        if len(self.hmap[val])==0: del self.hmap[val]     #hmap[val]为空删除该元素
        if i!=len(self.nums)-1:                 #删除的不是nums的末尾元素时
            lastk=self.nums[len(self.nums)-1]              #求末尾关键字lastk
            self.nums[i]=lastk                             #将元素lastk移到索引i处
            self.hmap[lastk].remove(len(self.nums)-1)           #hmap[lastk]中删除n-1
            self.hmap[lastk].add(i)
        self.nums.pop()                                    #从nums中删除末尾元素
        return True

    def getRandom(self)->int:
        j=random.randrange(0,len(self.nums),1)             #返回0~n-1的随机数
        return self.nums[j]

