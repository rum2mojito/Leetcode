class Solution:
    def titleToNumber(self, s: str) -> int:
        ret = 0
        eta = 1
        
        for i in range(len(s)):
            ret += ((ord(s[len(s)-i-1])-ord('A')) + 1) * eta
            eta *= 26
        
        return ret
        
