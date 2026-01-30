class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.binary(nums, target, True), self.binary(nums, target, False)]

    def binary(self, nums, target, findFirst):
        s, e = 0, len(nums) - 1
        ans = -1
        while s <= e:
            mid = (s + e) // 2
            if target > nums[mid]:
                s = mid + 1
            elif target < nums[mid]:
                e = mid - 1
            else:
                ans = mid
                if findFirst:
                    e = mid - 1
                else:
                    s = mid + 1
        return ans
#in tis que we have tar element 2 times we need to get arr containg starting and ending index. by binary search wwe check the mid element as target and then check for mid-1 & mid+1 element value.
        
