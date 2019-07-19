# use set to find item

class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        J_set = set(J)
        res = 0
        for node in S:
            if node in J_set:
                res += 1
        return res
