class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Step 1: Initialize a dictionary to store numbers and their indices
        num_to_index = {}
        
        # Step 2: Iterate through the list with index and value
        for i, num in enumerate(nums):
            # Step 3: Calculate the complement
            complement = target - num
            
            # Step 4: Check if the complement exists in the dictionary
            if complement in num_to_index:
                # Complement found, return the indices
                return [num_to_index[complement], i]
            
            # Add the current number and its index to the dictionary
            num_to_index[num] = i
        
        # Step 5: Return an empty list if no pair is found
        return []
