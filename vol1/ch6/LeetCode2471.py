from collections import deque
class Solution:
    def minimumOperations(self, root):
        ans=0
        if root==None:return ans
        qu=deque()      #定义一个队列qu
        qu.append(root)              #根结点(层次为1)进队
        while qu:                    #队不空循环
            n=len(qu)
            curp=[]
            for i in range(0,n):
                p=qu.popleft()           #出队一个结点
                curp.append(p.val)                 #当前层的结点值添加到curp
                if p.left!=None:                      #有左孩子时将其进队
                    qu.append(p.left)
                if p.right!=None:                     #有右孩子时将其进队
                    qu.append(p.right)
            ans+=self.minswaps(curp)
        return ans

    def minswaps(self,a):								#求a变为有序的最少交换次数
        b=a.copy()						#由a复制得到另外一个列表b
        b.sort()
        hmap={}          #记录排好序的元素位置
        for i in range(0,len(b)):hmap[b[i]]=i
        print(hmap)
        cnt=0
        for i in range(0,len(a)):
            while a[i]!=b[i]:           #可能需要多次交换
                tmp=a[hmap[a[i]]]			#注意应该采用传统交换方式
                a[hmap[a[i]]]=a[i]
                a[i]=tmp
                cnt+=1
        return cnt
