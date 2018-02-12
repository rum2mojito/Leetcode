// 26. Remove Duplicates from Sorted Array

class Solution:
    def removeDuplicates(self, A):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not A:
            return 0

        newTail = 0

        for i in range(1, len(A)):
            if A[i] != A[newTail]:
                newTail += 1
                A[newTail] = A[i]

        return newTail + 1
