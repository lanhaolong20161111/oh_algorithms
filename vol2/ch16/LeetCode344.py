class Solution:
    def reverseString(self, s: List[str]) -> None:
        self.rev(s,0,len(s)-1)
    def rev(self,s,i,j):
        if i<j:       #至少含两个字符
            s[i],s[j]=s[j],s[i]
            self.rev(s,i+1,j-1)
