class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        hset=set()
        for x in paths:
            hset.add(x[0])
        for x in paths:
            if x[1] not in hset:
                return x[1]
