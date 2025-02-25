class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m,n=len(matrix),len(matrix[0])
        i,j=0,n-1
        while True:
            if target==matrix[i][j]:return True
            elif target<matrix[i][j]:j-=1
            else: i+=1
            if i>=m  or j<0:return False
        return False 
