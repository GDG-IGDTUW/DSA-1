class Solution:
    def sortArray(self, nums):
        
        n = len(nums)
        
        # Heapify function
        def heapify(n, i):
            largest = i
            left = 2 * i + 1
            right = 2 * i + 2
            
            if left < n and nums[left] > nums[largest]:
                largest = left
                
            if right < n and nums[right] > nums[largest]:
                largest = right
                
            if largest != i:
                nums[i], nums[largest] = nums[largest], nums[i]
                heapify(n, largest)
        
        # Step 1: Build max heap
        for i in range(n // 2 - 1, -1, -1):
            heapify(n, i)
        
        # Step 2: Extract elements
        for i in range(n - 1, 0, -1):
            nums[0], nums[i] = nums[i], nums[0]
            heapify(i, 0)
        
        return nums
