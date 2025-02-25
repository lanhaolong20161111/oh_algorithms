from collections import deque
class Solution:
    def removeDuplicates(self, s: str) -> str:
        dq=deque()
        for i in range(0,len(s)):
            if dq and dq[-1]==s[i]:
                dq.pop()
            else:
                dq.append(s[i])
        return ''.join(dq)
