class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # Step 1: Initialize an empty set
        seen = set()
        
        # Step 2: Iterate through the list of numbers
        for num in nums:
            # Step 3: Check if the number is already in the set
            if num in seen:
                return True  # Duplicate found
            
            # Step 4: Add the number to the set
            seen.add(num)
        
        # Step 5: Return False if no duplicates are found
        return False