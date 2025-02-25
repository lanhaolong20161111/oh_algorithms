class Solution:
    def alienOrder(self, words: List[str]) -> str:
        myset=set()
        chars=set()      #存放所有字母
        degree=[0 for _ in range(0,256)]      #存放入度
        qu=deque()
        for word in words:    #提取所有不同的字母
            for ch in word:
                chars.add(ch)
        for i in range(0,len(words)-1):
            minlen=min(len(words[i]),len(words[i+1]))
            j=0
            while j<minlen:
                if words[i][j]!=words[i+1][j]:
                    myset.add(tuple([words[i][j],words[i+1][j]]))
                    break          #确定words[i][j]<words[i+1][j]的关系
                j+=1
            if j==minlen and len(words[i])>len(words[i+1]):
                return ""          #关系矛盾
        for e in myset:
            degree[ord(e[1])]+=1    #求e[1]的入度
        for ch in chars:
            if degree[ord(ch)]==0:qu.append(ch)
        ans=""
        while qu:
            ch=qu.popleft()     #出队字母ch
            ans+=ch
            for e in myset:     #用e遍历myset
                if e[0]==ch:
                    degree[ord(e[1])]-=1
                    if degree[ord(e[1])]==0:
                        qu.append(e[1])
        return ans if len(ans)==len(chars) else ""
