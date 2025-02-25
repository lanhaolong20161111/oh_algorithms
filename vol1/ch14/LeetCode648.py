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
    def search(self,s):       #查找s的前缀
        p,ans=self.root,""
        for c in s:
            if p.isend: return ans
            if p.ch[ord(c)-ord('a')]==None:return ""
            ans+=c
            p=p.ch[ord(c)-ord('a')]
        return ans
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        tr=Trie()                #定义字典树对象
        for s in dictionary:
            tr.insert(s)
        ans=""
        words=sentence.split()
        for word in words:   #分离出单词word
            str=tr.search(word)
            if str=="":ans+=word+' '
            else:ans+=str+' '
        return ans.strip()
