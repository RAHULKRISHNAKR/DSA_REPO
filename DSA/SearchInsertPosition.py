'''
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity
'''

class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # If the list is empty, the target should be inserted at index 0
        if nums == []:
            return 0
        
        # If the target is already in the list, return its index
        if target in nums:
            return nums.index(target)
        else:
            # If the target is greater than the last element, it should be inserted at the end
            if target > nums[len(nums) - 1]:
                return len(nums)
            
            # Iterate through the list to find the first element greater than the target
            for i in range(len(nums)):
                if nums[i] > target:
                    return i

        