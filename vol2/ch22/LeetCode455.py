class Solution:
  def findContentChildren(self, g: List[int], s: List[int]) -> int:
    g.sort()
    s.sort()
    n,m=len(g),len(s)
    ans=0
    i,j=0,0
    while i<n and j<m:
      if g[i]<=s[j]:
        ans,i=ans+1,i+1
      j+=1
    return ans
