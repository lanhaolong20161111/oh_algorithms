class MyHashSet:
    def __init__(self):
        self.MAXH=10000
        self.P=9997
        self.NULLKEY=-1
        self.DELKEY=-2
        self.ht=[self.NULLKEY]*self.MAXH

    def add(self, key: int) -> None:
        d=key%self.P
        while self.ht[d]!=key and self.ht[d]!=self.NULLKEY and self.ht[d]!=self.DELKEY:
            d=(d+1)%self.MAXH
        self.ht[d]=key

    def remove(self, key: int) -> None:
        d=self.hash(key)
        if self.ht[d]!=self.NULLKEY:
            self.ht[d]=self.DELKEY 

    def contains(self, key: int) -> bool:
        return self.ht[self.hash(key)]!=self.NULLKEY

    def hash(self,key):
        d=key%self.P
        while self.ht[d]!=key and self.ht[d]!=self.NULLKEY:
            d=(d+1)%self.MAXH
        return d
