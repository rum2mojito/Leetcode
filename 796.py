// 796. Rotate String 

class Solution:
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if A == B:
            return True
        l = len(A)
        for i in range (0,l):
            a = A[0]
            A = A[1:l]
            A = A[0:l-1] + a
            if A == B:
                return True
        return False
