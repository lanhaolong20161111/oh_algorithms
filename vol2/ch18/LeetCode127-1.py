class Solution:
    def ladderLength(self,beginWord:str,endWord:str,wordList:List[str])->int:
        dict=set()     #字典用dict表示
        visited=set()  #是否访问过
        for s in wordList:dict.add(s)
        if endWord not in dict:return 0
        qu=deque()
        qu.append(beginWord)
        visited.add(beginWord)
        ans=0
        while qu:
            ans+=1
            cnt=len(qu)
            for k in range(0,cnt):
                str=qu.popleft()        #出队str
                for i in range(0,len(str)): #对str每个字符进行改变
                    for j in range(0,26):
                        tmp=list(str)       #将str转换为列表
                        tmp[i]=chr(ord('a')+j); #修改tmp[i]
                        copystr=''.join(tmp)        #将tmp转换为字符串copystr
                        if copystr==endWord:
                            return ans+1
                        if copystr not in dict:
                            continue               #copystr不在字典中时跳过
                        if copystr in visited:
                            continue               #copystr已访问过时跳过
                        qu.append(copystr)
                        visited.add(copystr)
        return 0
