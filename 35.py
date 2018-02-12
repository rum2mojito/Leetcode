// 35. Search Insert Position

class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) is 0:
            return 0
        for i in range (len(nums)):
            if nums[i] >= target:
                return i
        return len(nums)
