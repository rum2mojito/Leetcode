// 690. Employee Importance

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> mp;
        for (Employee *employee : employees) {
            mp[employee->id] = employee;
        }
        
        queue<Employee*> q;
        q.push(mp[id]);
        int res=0;
        while (!q.empty()) {
            Employee *p = q.front();
            q.pop();
            res += p->importance;
            if ((p->subordinates).size() != 0) {
                for (int i : p->subordinates) {
                    q.push(mp[i]);
                }
            }
        }
        return res;
    }
};
