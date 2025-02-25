class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hmap=dict()
        for x in strs:
            key="".join((lambda x:(x.sort(),x)[1])(list(x)))
            if key in hmap:
                hmap[key].append(x)
            else:
                hmap[key]=[x]
        ans=[]                  #存放答案
        for v in hmap.values():
            ans.append(v)
        return ans
