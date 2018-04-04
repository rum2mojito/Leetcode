// 797. All Paths From Source to Target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> map(graph.size(), vector<int>(graph.size(),0)), res;
        vector<int> visited (graph.size(), 0), q;
        for (int i=0;i<graph.size();i++) {
            for (int j=0;j<graph[i].size();j++) {
                map[i][graph[i][j]] = 1;
            }
        }
        q.push_back(0);
        visited[0] = 1;
        helper (q, map, visited, res);
        return res;
    }
    
    void helper (vector<int> &q, vector<vector<int>> map, vector<int> &visited, vector<vector<int>> &res) {
        int posi = q[q.size()-1];
        if (posi == map[0].size()-1) {
            res.push_back(q);
            return;
        } 
        for (int i=0;i<map[posi].size();i++) {
            if (map[posi][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push_back(i);
                helper (q, map, visited, res);
                q.erase(q.end()-1);
                visited[i] = 0;
            }
        }
    }
};
