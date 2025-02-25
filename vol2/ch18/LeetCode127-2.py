class Solution:
    def ladderLength(self,beginWord:str,endWord:str,wordList:List[str])->int:
        self.dict=set()
        for s in wordList:self.dict.add(s)
        if endWord not in self.dict:return 0
        dist1,dist2={},{}
        qu1=deque()
        qu2=deque()
        qu1.append(beginWord)
        dist1[beginWord]=1
        qu2.append(endWord)
        dist2[endWord]=1
        while qu1 and qu2:
            ans=0
            if len(qu1)<=len(qu2):
                ans=self.extend(qu1,dist1,dist2)
            else:
                ans=self.extend(qu2,dist2,dist1)
            if ans>0:return ans
        return 0
    def extend(self,qu,dist1,dist2):
        cnt=len(qu)
        for k in range(0,cnt):
            str=qu.popleft()
            for i in range(0,len(str)):
                for j in range(0,26):
                    tmp=list(str)       #将str转换为列表
                    tmp[i]=chr(ord('a')+j); #修改tmp[i]
                    copystr=''.join(tmp)        #将tmp转换为字符串copystr
                    if copystr in dist2:   #找到目标，查找成功
                        return dist1[str]+dist2[copystr]
                    if copystr not in self.dict:
                        continue
                    if copystr in dist1:
                        continue
                    dist1[copystr]=dist1[str]+1
                    qu.append(copystr)
        return 0    #查找不成功
