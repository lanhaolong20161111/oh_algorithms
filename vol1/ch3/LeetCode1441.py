class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans=[]
        j=0							#遍历target数组
        for i in range(1,n+1):
            ans.append("Push")			#i进栈
            if  i!=target[j]:				#target数组的当前元素不等于i
                ans.append("Pop")		#出栈i
            else:                            #target数组的当前元素等于i
                j=j+1
            if j==len(target):			#target数组遍历完时退出循环
                break;
        return ans              