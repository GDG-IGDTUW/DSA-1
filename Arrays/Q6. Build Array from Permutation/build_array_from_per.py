def buildArray(nums):
    return [nums[nums[i]] for i in range(len(nums))]

# Example Usage:
nums = [0, 2, 1, 5, 3, 4]
output = buildArray(nums)
print(output)  # Output: [0, 1, 2, 4, 5, 3]
