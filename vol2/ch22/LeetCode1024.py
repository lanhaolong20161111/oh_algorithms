class Solution:
    def videoStitching(self,clips:List[List[int]], time:int)->int:
        n=len(clips)
        clips.sort(key=lambda x:x[0])   #按左端点递增排序
        ans=0              #存放答案
        preend=0           #当前片段的右端点
        i=0
        while preend<time:
            next=preend         #下一个片段的右端点
            while i<n and clips[i][0]<=preend:    #重叠
                next=max(next,clips[i][1])        #取最大的右端点
                i+=1
            ans+=1              #选择最大右端点的片段
            if next==preend:  #找不到新片段，无法合成视频
                return -1
            preend=next
        return ans
