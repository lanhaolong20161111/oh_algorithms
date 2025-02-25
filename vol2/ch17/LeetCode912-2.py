class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.mergesort(nums,0,len(nums)-1)
        return nums
    def mergesort(self,a,low,high):				#二路归并排序
        if low<high:
            mid=(low+high)//2
            self.mergesort(a,low,mid)
            self.mergesort(a,mid+1,high)
            self.merge(a,low,mid,high)
    def merge(self,a,low,mid,high):				#二路归并
        tmp=[]
        i,j=low,mid+1
        while i<mid+1 and j<high+1:
            if a[i]<a[j]:
                tmp.append(a[i])
                i+=1
            else:
                tmp.append(a[j])
                j+=1
        while i<mid+1:
            tmp.append(a[i]);
            i+=1
        while j<high+1:
            tmp.append(a[j])
            j+=1
        a[low:high+1]=tmp[:]
