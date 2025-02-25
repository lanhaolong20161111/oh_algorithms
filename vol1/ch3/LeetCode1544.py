class Solution:
    def makeGood(self, s: str) -> str:
        ans=[]
        for i in range(0,len(s)):
            if len(ans)>0 and ans[-1].lower()==s[i].lower() and ans[-1]!=s[i]:
                ans.pop()
            else:
                ans.append(s[i])
        return ''.join(ans)
