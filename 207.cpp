// 207. Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        pair<int,int> p;
        for (int i=0;i<prerequisites.size();i++) {
            p = prerequisites[i];
            graph[p.first].push_back(p.second);
        }
        
        // states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> v(numCourses, 0);
        
        for(int i = 0; i < numCourses; ++i)
            if(dfs(i, v)) return false;
        
        return true;
    }
    
    bool dfs(int cur, vector<int>& v) {
        if(v[cur] == 1) return true;
        if(v[cur] == 2) return false;
        
        v[cur] = 1;
        
        for(const int t : graph[cur])
            if(dfs(t, v)) return true;
        
        v[cur] = 2;
        
        return false;
    }
private:
    vector<vector<int>> graph;
};
