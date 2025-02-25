class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n=len(digits)
        if n==0:return []
        hmap={'2':"abc",'3':"def",'4':"ghi",'5':"jkl",'6':"mno",'7':"pqrs",'8':"tuv",'9':"wxyz"}    #映射表
        ans=[]
        if n==1:
            key=hmap[digits[0]]
            for c in key:ans.append(str(c))
            return ans
        subs=self.letterCombinations(digits[1:])
        key=hmap[digits[0]]
        for e in subs:
            for c in key:
                ans.append(str(c)+e)
        return ans
