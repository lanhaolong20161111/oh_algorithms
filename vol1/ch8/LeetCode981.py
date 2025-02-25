class TimeMap:
    def __init__(self):
        self.hmap={}

    def set(self,key:str,value: str,timestamp:int) -> None:
        if key not in self.hmap:
            self.hmap[key]=([timestamp],{timestamp:value})
        else:
            self.hmap[key][0].append(timestamp)
            self.hmap[key][1][timestamp]=value

    def get(self, key:str,timestamp: int) -> str:
        if key not in self.hmap: return ""
        e=self.hmap.get(key)
        i=bisect.bisect(e[0],timestamp)
        if i==0: return ""
        return e[1][e[0][i-1]]
