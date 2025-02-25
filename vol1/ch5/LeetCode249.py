class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        hmap=dict()
        for x in strings:
            key=""
            for i in range(1,len(x)):
                key+=chr((ord(x[i])-ord(x[0])+26)%26)     #当前字符与首字符的距离
            if key in hmap:
                hmap[key].append(x)
            else:
                hmap[key]=[x]
        ans=[]                  #存放答案
        for v in hmap.values():
            ans.append(v)
        return ans
