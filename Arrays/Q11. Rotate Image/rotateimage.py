class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:

        l, r = 0, len(matrix) -1
        
        while l < r:
            for i in range(r - l):
                top, bottom = l, r
                topLeft = matrix[top][l +i]
                matrix[top][l +i] = matrix[bottom - i][l]
                 # Move bottom right into bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i]
                
                # Move top right into bottom right
                matrix[bottom][r - i] = matrix[top + i][r]
                
                # Move top left into top right
                matrix[top + i][r] = topLeft
            r -= 1
            l += 1
sol = Solution()
matrix = [[1,2,3],[4,5,6],[7,8,9]]
print(sol.rotate(matrix))
print(matrix)
