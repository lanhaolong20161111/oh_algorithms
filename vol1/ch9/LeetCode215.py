class Heap:                                 		#堆数据结构的实现
    def __init__(self):
        self.n=0                                  #堆中元素个数
        self.R=[]                            #用R[0..n-1]存放堆中元素

    def cmp(self,a,b):                        #用于创建大根堆
        return a<b

    def siftDown(self,low,high):      #R[low..high]的自顶向下筛选
        i=low
        j=2*i+1
        tmp=self.R[i]                         #tmp临时保存根结点
        while j<=high:                   #只对R[low..high]的元素进行筛选
            if j<high and self.cmp(self.R[j],self.R[j+1]):
                j+=1                            # j指向右孩子
            if self.cmp(tmp,self.R[j]):                   #若反序
                self.R[i]=self.R[j]                 #将R[j]调整到双亲位置上
                i,j=j,2*i+1                  #修改i和j值,以便继续向下筛选
            else: break                     #若正序则结束
        self.R[i]=tmp                           #原根结点放入最终位置

    def siftUp(self,j):                        #自底向上筛选:从叶子结点j向上筛选
        i=(j-1)//2                          #i指向R[j]的双亲
        tmp=self.R[j]
        while j!=0: 
            if self.cmp(self.R[i],tmp):                    #若反序则交换
                self.R[j]=self.R[i]
                j,i=i,(j-1)//2
            else: break;                 #到达根结点时结束
        self.R[j]=tmp

    def push(self,e):                              #插入元素e
        self.R.append(e)                     #将e添加到末尾
        self.n+=1                                    #堆中元素个数增1
        if self.n==1:return                           #e作为根结点的情况
        self.siftUp(self.n-1)                              #从叶子结点R[n-1]向上筛选

    def pop(self):                               #删除堆顶元素
        e=self.R[0]                           #取出堆顶元素
        self.R[0]=self.R[self.n-1]                        #用尾元素覆盖R[0]
        self.R.pop()
        self.n-=1                                    #元素个数减少1
        if self.n>1: 
            self.siftDown(0,self.n-1)                       #筛选为一个堆
        return e

    def top(self):                              #取堆顶元素
        return self.R[0]

    def empty(self):                          #判断堆是否为空
        if self.n==0:return True
        else: return False

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq=Heap()
        for i in range(0,len(nums)):
            pq.push(nums[i]);
        for i in range(0,k-1):
            pq.pop()
        return pq.top()
