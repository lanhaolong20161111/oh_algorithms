class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n=len(nums)
        a=[]                              #a存放每个元素及其索引
        self.counts=[]
        for i in range(0,n):
            a.append([nums[i],i])            #a保存每个元素中及其下标 
            self.counts.append(0)                 #初始化counts所有元素为0 
        self.mergesort(a,0,n-1)
        return self.counts
    def mergesort(self,a,low,high):      #二路归并排序
        if low<high:
            mid=(low+high)//2
            self.mergesort(a,low,mid)
            self.mergesort(a,mid+1,high)
            self.merge(a,low,mid,high)
    def merge(self,a,low,mid,high):              #二路归并
        i,j=low,mid+1
        tmp=[]                           #分配临时归并空间tmp
        while i<=mid and j<=high:
            if a[i][0]<=a[j][0]:         #a[i]元素较小
                tmp.append(a[i])           #归并a[i]
                self.counts[a[i][1]]+=j-mid-1     #累加a[i]位置前移的元素个数
                i+=1
            else:                                  #a[j]元素较小
                tmp.append(a[j])                     #归并a[j]
                j+=1
        while i<=mid:                                        #第1个段没有遍历完
            tmp.append(a[i])
            self.counts[a[i][1]]+=high-mid
            i+=1
        while j<=high:                                       #第2个段没有遍历完
            tmp.append(a[j])
            j+=1
        a[low:high+1]=tmp[:]
