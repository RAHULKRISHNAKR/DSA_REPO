'''
Given a non-empty array of integers nums, every element 
appears twice except for one. Find that single one.

You must implement a solution with a linear runtime 
complexity and use only constant extra space.
'''

class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize result to 0
        result = 0
        
        # Iterate through each number in the list
        for num in nums:
            # XOR the result with the current number
            result ^= num
        
        # The result will be the single number that appears only once
        return result