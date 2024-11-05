/*Quick Sort:
This algorithm works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.

Algorithm:

Choose the last element of the array as the pivot.
Partition the array such that elements with values less than the pivot come before the pivot, while elements with values greater than the pivot come after it. After this partitioning step, the pivot is in its final sorted position.
Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
Repeat the process until the entire array is sorted.
Example:

Given array: 5, 8, 1, 4, 2 Choose 2 as pivot: 1, 4, 5, 8 After partitioning: 1, 4, 2, 5, 8

Recursively apply the steps to the sub-arrays:

Left sub-array: 1, 4, 2 After partitioning: 1, 2, 4 Recursively apply the steps to the sub-arrays:

1, 2: 1, 2

Right sub-array: 5, 8 After partitioning: 5, 8 Recursively apply the steps to the sub-arrays:

5, 8: 5, 8

So, the final sorted array is: 1, 2, 4, 5, 8

2. Merge Sort:
This algorithm follows a divide-and-conquer approach to sort the array. The algorithm divides the array into two halves, recursively sorts them, and then merges the sorted halves to produce the final sorted array.

Algorithm:

If the array has only one element, return it. This is the base case for the recursion.
Divide the array into two halves.
Recursively apply the merge sort algorithm to each half.
Merge the two halves and return the result.
Example:

Given array: 5, 8, 1, 4, 2 Divide the array into two halves: 5, 8 and 1, 4, 2 Recursively apply the steps to the halves:

5, 8: 5, 8

1, 4, 2: 1, 2, 4

After sorting the halves, merge them:

1, 2, 4, 5, 8

So, the final sorted array is: 1, 2, 4, 5, 8

3. Heap Sort:
This algorithm works by dividing the array into a sorted and an unsorted region and iteratively shrinking the unsorted region by extracting the largest element and moving it to the sorted region.

Algorithm:

Build a max heap from the input data.
At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
Repeat the above steps until the size of the heap is 1.
Example:

Given array: 5, 8, 1, 4, 2 Build a max heap: 8, 5, 1, 4, 2

Heap after removing the largest element and re-heapifying: 5, 8, 1, 4, 2

Repeat the process: 5, 8, 1, 4, 2

So, the final sorted array is: 1, 2, 4, 5, 8

This code provides implementations for the requested algorithms, along with a user-friendly interface that allows the user to choose which sorting algorithm to use
*/