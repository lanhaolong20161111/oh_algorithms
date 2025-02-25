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
                p.cnt+=1
            p=p.ch[ord(c)-ord('a')]
        p.isend=True
    def maxprefix(self):                #查找最大前缀
        ans=""
        p,k=self.root,0
        while p.cnt==1 and p.isend==False:
            for k in range(0,26):
                if p.ch[k]!=None:
                    ans+=chr(k+ord('a'))
                    break
            p=p.ch[k]
        return ans
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        tr=Trie()                   #定义字典树对象
        for s in strs:
            if len(s)==0:return ""
            tr.insert(s)
        return tr.maxprefix();
