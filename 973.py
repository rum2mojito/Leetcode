class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        dis = []
        for i in range (len(points)):
            dis.append((i, points[i][0]*points[i][0] + points[i][1]*points[i][1]))
            
        dis.sort(key=lambda elem: elem[1])
        
        ret = []
        for i in range(K):
            ret.append(points[dis[i][0]])
            
        return ret
        
