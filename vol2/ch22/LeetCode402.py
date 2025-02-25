class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        n=len(num)
        if n<=k:return "0"
        num=list(num)       #转换为列表
        i=0
        while k>0:          #在num中删除k位
            while i<n-1 and num[i]<=num[i+1]:
                i+=1        #找一个递减(含相同元素)区间
            num.pop(i)        #删除该递减区间元素num[i]
            k,n=k-1,n-1
            if i>0:i-=1    #非首字符时
        while len(num)>1 and num[0]=='0':
            num.pop(0)      #删除前导0
        return ''.join(num)     #转换为字符串
