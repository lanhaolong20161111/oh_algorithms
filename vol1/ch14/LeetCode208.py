class TNode:                         #字典树结点类型
    def __init__(self):
        self.ch=[None]*26
        self.isend=False
class Trie:							#字典树类
    def __init__(self):
        self.root=TNode()         #根结点
    def searchPrefix(self,s):
        p=self.root
        for c in s:
            if p.ch[ord(c)-ord('a')]==None:return None
            p=p.ch[ord(c)-ord('a')]
        return p
    def insert(self, word: str) -> None:
        p=self.root
        for c in word:
            if p.ch[ord(c)-ord('a')]==None:
                p.ch[ord(c)-ord('a')]=TNode()
            p=p.ch[ord(c)-ord('a')]
        p.isend=True
    def search(self, word: str) -> bool:
        p=self.searchPrefix(word)
        return p!=None and p.isend==True
    def startsWith(self, prefix: str) -> bool:
        return self.searchPrefix(prefix)!=None
