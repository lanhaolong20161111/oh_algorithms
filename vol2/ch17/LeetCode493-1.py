class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        self.ans=0
        self.mergesort(nums,0,len(nums)-1)
        return self.ans
    def mergesort(self,a,low,high):    #二路归并排序
        if low==high:return
        mid=(low+high)//2
        self.mergesort(a,low,mid)                            #a[low..mid]排序
        self.mergesort(a,mid+1,high)                     #a[mid+1..high]排序
        j=mid+1                                        #合并之前求翻转对
        for i in range(low,mid+1):
            while j<=high and a[i]>2*a[j]:j+=1
            self.ans+=(j-mid-1)
        a[low:high+1]=sorted(a[low:high+1])  #合并操作
