class SegmentTree:              #线段树类
    def __init__(self,length):
        self.ST=[0]*(4*length)             #存放线段树

    def QueryRange(self,root,L,R,i,j):
        if L>=i and R<=j:return self.ST[root]
        else:
            mid=(L+R)//2
            lsum,rsum=0,0
            if i<=mid:lsum=self.QueryRange(2*root+1,L,mid,i,j)
            if j>mid: rsum=self.QueryRange(2*root+2,mid+1,R,i,j)
            return lsum+rsum
    def UpdateOne(self,root,L,R,i,x):
        if L==R:self.ST[root]+=x
        else:
            mid=(L+R)//2
            if i<=mid:self.UpdateOne(2*root+1,L,mid,i,x)
            else:self.UpdateOne(2*root+2,mid+1,R,i,x)
            self.ST[root]=self.ST[2*root+1]+self.ST[2*root+2]

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n=len(nums)
        hmap,idx={},0
        for x in sorted(nums):
            if x not in hmap:
                hmap[x]=idx;idx+=1
        st=SegmentTree(n)
        ans=[]
        for i in range(n-1,-1,-1):
            x=nums[i]
            id=hmap[x]
            if id>0:
                sum=st.QueryRange(0,0,n-1,0,id-1)
                ans.append(sum)
            else: ans.append(0)
            st.UpdateOne(0,0,n-1,id,1)
        return list(reversed(ans))
