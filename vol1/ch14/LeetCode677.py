class TNode:                         #字典树结点类型
    def __init__(self):
        self.ch=[None]*26
        self.val=0                  #值
class MapSum:
    def __init__(self):
        self.root=TNode()                #字典树根结点
        self.cnt={}                      #哈希映射:计数器
    def insert(self, key: str, val: int) -> None:
        delta=val
        if key in self.cnt:delta-=self.cnt[key]
        self.cnt[key]=val
        p=self.root
        for c in  key:
            if p.ch[ord(c)-ord('a')]==None:
                p.ch[ord(c)-ord('a')]=TNode()
            p=p.ch[ord(c)-ord('a')];
            p.val+=delta
    def sum(self, prefix: str) -> int:
        p=self.root
        for c in prefix:
            if p.ch[ord(c)-ord('a')]==None:return 0
            else:p=p.ch[ord(c)-ord('a')]
        return p.val
