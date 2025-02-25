class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n=len(digits)
        if n==0:return []
        hmap={'2':"abc",'3':"def",'4':"ghi",'5':"jkl",'6':"mno",'7':"pqrs",'8':"tuv",'9':"wxyz"}  #映射表
        ans=[""]
        for i in range(0,n):
            curd=hmap[digits[i]]
            ans1=ans
            ans=[]
            for x1 in ans1:
                for y1 in curd:
                    ans.append(x1+y1)
        return ans
