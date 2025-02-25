class Solution:
    def UpdateOne(self,root,L,R,i):
        if L==R:self.ST[root]+=1
        else:
            mid=(L+R)>>1
            if i<=mid:self.UpdateOne(2*root+1,L,mid,i)
            else:self.UpdateOne(2*root+2,mid+1,R,i)
            self.ST[root]=self.ST[2*root+1]+self.ST[2*root+2]
    def QueryRange(self,root,L,R,i,j):
        if i<=L and j>=R:return self.ST[root]
        else:
            mid=(L+R)>>1
            ans=0
            if i<=mid: ans+=self.QueryRange(2*root+1,L,mid,i,j)
            if j>mid: ans+=self.QueryRange(2*root+2,mid+1,R,i,j)
            return ans

    def countRangeSum(self, nums: List[int],lower:int,upper:int)->int:
        n=len(nums)
        presum=[0]*(n+1)            #前缀和数组
        presum[0]=0
        for i in range(1,n+1):
            presum[i]=presum[i-1]+nums[i-1]
        a=[]                        #离散化
        for x in presum:
            a.append(x)
            a.append(x-lower)
            a.append(x-upper)
        hmap={}
        idx=0
        for x in sorted(a):
            if x not in hmap:
                hmap[x]=idx;idx+=1
        self.ST=[0]*(6*idx)
        ans=0
        for x in presum:
            i,j,k=hmap[x-upper],hmap[x-lower],hmap[x]
            ans+=self.QueryRange(0,0,idx-1,i,j)
            self.UpdateOne(0,0,idx-1,k)
        return ans
