class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        cnt=[0]*26;
        visited=[0]*26;
        for c in s:                 #累计每个字母出现的次数
            cnt[ord(c)-ord('a')]=cnt[ord(c)-ord('a')]+1
        st=[];
        for c in s:
            if visited[ord(c)-ord('a')]==1:   #c在栈中的情况
                cnt[ord(c)-ord('a')]=cnt[ord(c)-ord('a')]-1;
            else:           #c不在栈中的情况
                while st and st[-1]>c and cnt[ord(st[-1])-ord('a')]>=1:
                    visited[ord(st[-1])-ord('a')]=0   #出栈
                    st.pop()
                st.append(c)
                cnt[ord(c)-ord('a')]=cnt[ord(c)-ord('a')]-1
                visited[ord(c)-ord('a')]=1
        return ''.join(st)
