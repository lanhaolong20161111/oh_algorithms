class TNode:                         #字典树结点类型
    def __init__(self):
        self.ch=[None]*26
        self.cnt=0                          #表示该结点代表的字母出现了多少次
        self.isend=False
class Trie:            #字典树类
    def __init__(self):
        self.root=TNode()       #根结点
    def insert(self,s):                         #向root中插入字符串s
        p=self.root
        for c in s:
            if p.ch[ord(c)-ord('a')]==None:
                p.ch[ord(c)-ord('a')]=TNode()
            p=p.ch[ord(c)-ord('a')]
        p.cnt+=1
    def dfs(self,root,s,pos):   #深度优先搜索字典树
        ans=0
        if root.cnt>0:
            ans+=root.cnt
            root.cnt=0           #避免重复查找
        for k in range(0,26):
            if root.ch[k]:
                nextpos=s.find(chr(ord('a')+k),pos)
                if nextpos!=-1:
                    ans+=self.dfs(root.ch[k],s,nextpos+1)
        return ans
    def Count(self,s):           #求字典树中s子序列的个数
        return self.dfs(self.root,s,0)
class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        tr=Trie()                #定义字典树对象
        for word in words:
            tr.insert(word);
        return tr.Count(s)
